public with sharing class FilesRecipes {
    public class FileAndLinkObject {
        public Blob fileContents { get; set; }
        public Id attachedTo { get; set; }
        public String fileName { get; set; }
    }

    public class FilesRecipesException extends Exception {
    }

    public enum GenericFileType {
        IMAGE,
        AUDIO,
        DOCUMENT,
        ALL
    }

    public static void createFileFromStringAttachedToRecord(
        String text,
        Id firstLocation
    ) {
        Blob fileContents = Blob.valueOf(text);
        createFileAttachedToRecord(
            fileContents,
            firstLocation,
            'AwesomeFile1'
        );
    }

    public static Database.SaveResult createFileAttachedToRecord(
        Blob fileContents,
        Id attachedTo,
        String fileName
    ) {
        ContentVersion fileToUpload = new ContentVersion();
        fileToUpload.ContentLocation = 'S';
        fileToUpload.PathOnClient = fileName;
        fileToUpload.Title = fileName;
        fileToUpload.VersionData = fileContents;
        fileToUpload.FirstPublishLocationId = attachedTo;
        Database.SaveResult saveResult;
        try {
            saveResult = Database.insert(fileToUpload, AccessLevel.USER_MODE);
        } catch (DmlException DMLe) {
            System.debug(LoggingLevel.INFO, 'Failed to insert fileToUpload, error is: ' + DMLe.getMessage());
        }
        return saveResult;
    }

    public static Database.SaveResult createFileAttachedToRecord(
        FilesRecipes.FileAndLinkObject toCreate
    ) {
        return createFileAttachedToRecord(
            toCreate.fileContents,
            toCreate.attachedTo,
            toCreate.fileName
        );
    }

    public static List<Database.SaveResult> createFilesAttachedToRecords(
        List<FilesRecipes.FileAndLinkObject> toCreate
    ) {
        List<ContentVersion> filesToCreate = new List<ContentVersion>();
        for (FilesRecipes.FileAndLinkObject files : toCreate) {
            ContentVersion fileToUpload = new ContentVersion();
            fileToUpload.ContentLocation = 'S';
            fileToUpload.PathOnClient = files.fileName;
            fileToUpload.Title = files.fileName;
            fileToUpload.VersionData = files.fileContents;
            fileToUpload.FirstPublishLocationId = files.attachedTo;
            filesToCreate.add(fileToUpload);
        }

        List<Database.SaveResult> saveResult = new List<Database.SaveResult>();
        try {
            saveResult = Database.insert(filesToCreate, AccessLevel.USER_MODE);
        } catch (DmlException DMLe) {
            System.debug(LoggingLevel.INFO, 'Failed to insert filesToUpload, error is: ' + DMLe.getMessage());
        }
        return saveResult;
    }

    @SuppressWarnings('PMD.ApexCRUDViolation')
    public static List<ContentVersion> getFilteredAttachmentsForRecord(
        FilesRecipes.GenericFileType genericFileType,
        Id recordId
    ) {
        Map<String, Object> recordBind = new Map<String, Object>{
            'recordId' => recordId
        };
        List<ContentDocumentLink> links = new List<ContentDocumentLink>();
        String queryString =
            'SELECT ContentDocumentId' +
            ' FROM ContentDocumentLink' +
            ' WHERE ' +
            ' LinkedEntityId = :recordId';

        switch on genericFileType {
            when AUDIO {
                queryString += ' AND ContentDocument.FileType IN (\'M4A\')';
            }
            when IMAGE {
                queryString += ' AND ContentDocument.FileType IN (\'JPG\', \'GIF\', \'PNG\', \'JPEG\')';
            }
            when DOCUMENT {
                queryString += ' AND ContentDocument.FileType IN (\'WORD_X\', \'EXCEL_X\', \'POWER_POINT_X\', \'PDF\')';
            }
            when ALL {
                queryString += '';
            }
        }
        links = Database.queryWithBinds(
            queryString,
            recordBind,
            AccessLevel.USER_MODE
        );

        Set<Id> fileIds = new Set<Id>();
        for (ContentDocumentLink cdl : links) {
            fileIds.add(cdl.ContentDocumentId);
        }
        return [
            SELECT Id, Title
            FROM ContentVersion
            WHERE ContentDocumentId IN :fileIds AND IsLatest = TRUE
            WITH USER_MODE
            ORDER BY CreatedDate
        ];
    }

    public static Database.SaveResult publishContent(ContentDocumentLink cdl) {
        ContentDistribution dist = new ContentDistribution();

        dist.Name = 'new distributrion of content';
        dist.PreferencesAllowOriginalDownload = true;
        dist.PreferencesAllowPDFDownload = true;
        dist.PreferencesAllowViewInBrowser = true;
        dist.RelatedRecordId = cdl.LinkedEntityId;
        dist.ContentVersionId = cdl.ContentDocument.LatestPublishedVersionId;

        try {
            return Database.insert(dist, AccessLevel.USER_MODE);
        } catch (DmlException DMLe) {
            System.debug(LoggingLevel.INFO, DMLe.getMessage());
            throw new FilesRecipesException(DMLe.getMessage());
        }
    }
}