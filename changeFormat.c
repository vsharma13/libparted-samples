#include <error.h>
#include <stdio.h>

#include <parted/parted.h>

int main(int argc, char* argv[])
{
    PedDevice* device;
    PedDisk* disk;
    PedPartition* part;
    PedFileSystemType* fstype;

    if(argc != 2)
        error(EXIT_FAILURE, 0, "wrong number of arguments");
    device = ped_device_get(argv[1]);

    disk = ped_disk_new(device);
    if(disk == NULL)
    {
        ped_device_destroy(device);
        error(EXIT_FAILURE, -1, "error getting the disk");
    }

    // delete all partitions
    ped_disk_delete_all(disk);
   
    ped_disk_commit_to_dev(disk);

    ped_partition_destroy(part);
    ped_disk_destroy(disk);
    ped_device_destroy(device);

    return 0;
}
