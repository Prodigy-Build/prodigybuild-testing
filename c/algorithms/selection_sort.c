 #include <stdio.h>
 #include <stdlib.h>
+#include "acutest.h"
 
 void print_arr(int *ptr, int size)
 {
     putchar('[');
@@ -33,6 +34,19 @@ int *find_min(int *ptr, int size)
     return (min);
 }
 
+/* Unit test example */
+void test_selection_sort(void)
+{
+    int arr[] = {5, 2, 8, 1, 9};
+    int expected[] = {1, 2, 5, 8, 9};
+    int size = sizeof(arr) / sizeof(arr[0]);
+    
+    selection_sort(arr, size);
+    
+    for(int i = 0; i < size; i++)
+    {
+        TEST_CHECK(arr[i] == expected[i]);
+    }
+}
 
 void selection_sort(int *ptr, int size)
 {
@@ -51,5 +65,6 @@ int main(int argc, char *argv[])
     print_arr(arr, size);
 
     selection_sort(arr, size);
+    test_selection_sort();
     
     printf("After sorting:  ");
@@ -58,3 +73,4 @@ int main(int argc, char *argv[])
 
     free(arr);
     return EXIT_SUCCESS;
+}
