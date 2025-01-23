#include "list.h"
#include <stdio.h>

int main() {
        LinkedList *append_list = new_list();
        if (append_list == NULL) {
                return -1;
        }

        printf("(1/6) Testing append...\n");
        append(append_list, 1);
        append(append_list, 2);
        append(append_list, 3);
        printf("Expected output: [1, 2, 3]\nOutput: ");
        print_list(append_list);

        drop_list(append_list);

        printf("\n(2/6) Testing insert_front...\n");

        LinkedList *insertion_list = new_list();
        if (insertion_list == NULL) {
                return -1;
        }
        insert_front(insertion_list, 3);
        insert_front(insertion_list, 2);
        insert_front(insertion_list, 1);

        printf("Expected output: [1, 2, 3]\nOutput: ");
        print_list(insertion_list);

        printf("\n(3/6) Testing pop_n...\n");
        pop_n(insertion_list, 1);
        pop_n(insertion_list, 1);
        pop_n(insertion_list, 0);

        printf("Expected output: \nOutput: ");
        print_list(insertion_list);

        printf("\n(4/6) Testing insert_n...\n");
        insert_n(insertion_list, 2, 0);
        insert_n(insertion_list, 3, 1);
        insert_n(insertion_list, 1, 0);
        insert_n(insertion_list, 0, 0);
        insert_n(insertion_list, 5, 4);
        insert_n(insertion_list, 4, 4);

        printf("Expected list: [0, 1, 2, 3, 4, 5]\nOutput: ");
        print_list(insertion_list);

        printf("\n(5/6) Testing length attribute...\n");
        printf("Expected output: 6.\nOutput: ");
        printf("%d\n", insertion_list->length);

        drop_list(insertion_list);

        LinkedList *get_list = new_list();
        if (get_list == NULL) {
                return -1;
        }
        printf("\n(6/6) Testing get...\n");
        append(get_list, 1);
        append(get_list, 2);
        append(get_list, 3);


        printf("Expected output: [1, 2, 3]\nOutput: ");
        printf("[%d, ", get(get_list, 0));
        printf("%d, ", get(get_list, 1));
        printf("%d]\n", get(get_list, 2));

        drop_list(get_list);
        return 0;
}
