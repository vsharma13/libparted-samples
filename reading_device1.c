#include <error.h>
#include <stdio.h>

#include <parted/parted.h>

int main(int argc, char *argv[])
{
    char* size;
    char* transport[13] = {"unknow", "scsi", "ide", "dac960", "cpqarray",
                           "file", "ataraid", "i2o", "udb", "dasd", "viodasd",
                           "sx8", "dm"};
    PedDevice* device;

    if(argc != 2)
        error (EXIT_FAILURE, 0, "wrong number of arguments");

    device = ped_device_get(argv[1]);
    if(device == NULL)
        return 1;

    size = ped_unit_format_byte(device, device->length * device->sector_size);
    if(size == NULL)
        return 1;

    printf("Model: %s\n", device->model);
    printf("Transport: %s\n", transport[device->type]);
    printf("Size: %s\n", size);
    printf("Sector size (logical/physical): %lldB/%lldB\n",
           device->sector_size,
           device->phys_sector_size);

    free(size);
    return 0;
}
