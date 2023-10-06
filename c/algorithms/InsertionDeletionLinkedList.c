int main() {
    head = NULL;
    int ch;
    while (1) {
        printf("\n\t\t**MENU**\n\t1. Insert at begining\n\t2. Insert at nth position\n\t3. Insert at end\n\t4. Delete at begining\n\t5. Delete at end\n\t6. Delete nth node\n\t7. Display\n\t8. Exit\n");
        printf("\n\tEnter your choice: ");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
                printf("\nEnter value to be inserted: ");
                int v1;
                scanf("%d",&v1);
                InsertAtBegin(v1);
                break;
            case 2:
                printf("\nEnter position to insert value: ");
                int v2 , pos1;
                scanf("%d",&pos1);
                printf("Enter value to be inserted: ");
                scanf("%d",&v2);
                InsertAtnthNode(pos1 , v2);
                break;
            case 3:
                printf("\nEnter value to insert at end: ");
                int v3;
                scanf("%d",&v3);
                InsertAtEnd(v3);
                break;
            case 4:
                DeleteAtBegin();
                break;
            case 5:
                DeleteAtEnd();
                break;
            case 6:
                printf("\nEnter position to delete element: ");
                int pos2;
                scanf("%d",&pos2);
                DeletenthNode(pos2);
                break;
            case 7:
                Display();
                break;
            case 8:
                printf("\n\t**THANK YOU!**\n");
                exit(0);
            default: 
                printf("\n\t**Chose a valid option**\n"); 
        }       
    }
    return 0;
}