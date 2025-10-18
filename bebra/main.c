#include <stdio.h>
#include "Polygone.h"

void print_menu() {
    printf("\n--- POLYGON MANIPULATION MENU ---\n");
    printf("1. (a) Add polygon from console\n");
    printf("2. (c) Display all polygons from file\n");
    printf("3. (d) Delete polygon by index\n");
    printf("4. (g) Find polygon with MINIMUM area\n");
    printf("5. (h) Count convex polygons\n");
    printf("6. (i) Filter convex polygons to a new file\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

int main() {
    const char* main_db = "polygons.bin";
    int choice;

    do {
        print_menu();
        // Check for valid integer input
        if (scanf("%d", &choice) != 1) {
            choice = -1; // Assign an invalid choice to trigger the default case
            // Clear the input buffer in case of non-integer input
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1:
                add_polygone_from_console(main_db);
                break;
            case 2:
                display_all_polygons(main_db);
                break;
            case 3: {
                NTYPE index;
                printf("Enter index to delete: ");
                scanf("%u", &index);
                if (delete_polygone_by_index(main_db, index)) {
                    printf("Successfully deleted.\n");
                } else {
                    printf("Error: index not found.\n");
                }
                break;
            }
            case 4: {
                Polygone p = {0, NULL};
                if (find_min_area_polygone(main_db, &p)) {
                    printf("Found polygon with the minimum area:\n");
                    // Print the result
                    printf("Vertices: %u, Area: %.2f\n", p.n, area_polygone(&p));
                    free_polygone(&p);
                } else {
                    printf("Could not find (file is empty?).\n");
                }
                break;
            }
            case 5:
                printf("Number of convex polygons: %u\n", count_convex_polygons(main_db));
                break;
            case 6: {
                const char* filtered_db = "convex_only.bin";
                filter_polygons(main_db, filtered_db, is_convex);
                printf("Filtered polygons saved to '%s'. Displaying content:\n", filtered_db);
                display_all_polygons(filtered_db);
                break;
            }
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}