#include <error.h>
#include <stdlib.h>

#include <parted/parted.h>

int main(int argc, char* argv[])
{
    PedDevice* device;
    PedPartition* part = NULL;
    PedDisk* disk;
    if(argc != 2)
        error(EXIT_FAILURE, 0, "wrong number of arguments");

    device = ped_device_get(argv[1]);
    if(device == NULL)
    {
        error(EXIT_FAILURE, 1, "error getting the device");
    }

    disk = ped_disk_new(device);
    int count = ped_disk_get_primary_partition_count(disk);
    printf("%s have %d primary partitions\n", argv[1], count);

    return 0;
}
