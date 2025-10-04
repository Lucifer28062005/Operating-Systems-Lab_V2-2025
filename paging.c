#include <stdio.h>

#define LOGICAL_ADDRESS_SPACE 1024
#define PAGE_SIZE 128
#define NUM_PAGES (LOGICAL_ADDRESS_SPACE / PAGE_SIZE)
#define NUM_FRAMES 8

int main() {
    // Predefined page table mapping
    int page_table[NUM_PAGES] = {3, 5, -1, 7, 2, 6, 0, 4};

    int logical_address;

    // Print system details
    printf("Logical Address Space = %d bytes\n", LOGICAL_ADDRESS_SPACE);
    printf("Page Size = %d bytes\n", PAGE_SIZE);
    printf("Number of Pages = %d\n", NUM_PAGES);
    printf("Number of Frames = %d\n", NUM_FRAMES);

    // Print Page Table
    printf("Page Table:\n");
    for (int i = 0; i < NUM_PAGES; i++) {
        printf("Page %d -> Frame %d\n", i, page_table[i]);
    }

    // Input logical address
    printf("Enter a logical address (0 - %d): ", LOGICAL_ADDRESS_SPACE - 1);
    scanf("%d", &logical_address);

    // Validate logical address
    if (logical_address < 0 || logical_address >= LOGICAL_ADDRESS_SPACE) {
        printf("Invalid logical address\n");
        return 0;
    }

    // Extract page number and offset
    int page_number = logical_address / PAGE_SIZE;
    int offset = logical_address % PAGE_SIZE;

    // Frame number from page table
    int frame_number = page_table[page_number];

    // Physical address calculation
    int physical_address = frame_number * PAGE_SIZE + offset;

    // Output results in required format
    printf("Logical Address %d is in:\n", logical_address);
    printf("Page Number = %d\n", page_number);
    printf("Offset = %d\n", offset);
    printf("Frame Number from Page Table = %d\n", frame_number);
    printf("Physical Address = (Frame %d * %d) + %d = %d\n",
           frame_number, PAGE_SIZE, offset, physical_address);

    return 0;
}
