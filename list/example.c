#include "list.h"

int main() {
        LinkedList *list = new_list();


        append(list, 3);
        insert_front(list, 1);
        insert_n(list, 2, 1);
        insert_front(list, 0);
        pop_n(list, 0);

        print_list(list);
        drop_list(list);

        return 0;
}
