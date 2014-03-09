#include <error.h>
#include <stdio.h>

#include <parted/parted.h>

int main(int argc, char* argv[])
{
    PedDevice* device;
    PedDisk* disk;
    PedPartition* part;
    int i, last_partition_num;

    if(argc != 2)
        error(EXIT_FAILURE, 0, "wrong number of arguments");

    device =  ped_device_get(argv[1]);
    if(device == NULL)
        error(EXIT_FAILURE, -1, "error getting the device");

    disk = ped_disk_new(device);
    if(disk == NULL)
        error(EXIT_FAILURE, -2, "error getting the disk");
    
    last_partition_num = ped_disk_get_last_partition_num(disk);
    for(i = 1; i >= last_partition_num; i++)
    {
        part = ped_disk_get_partition(disk, i);
        printf("the partition 0 have a file system: %s\n", part->fs_type->name);
    }
    return 0;
}
