#include <error.h>
#include <stdio.h>

#include <parted/parted.h>

int main(int argc, char* argv[])
{
    PedDevice* device;
    PedDisk* disk_old;
    PedDisk* disk;
    PedDiskType* type;

    if(argc != 3)
        error(EXIT_FAILURE, 0, "wrong number of arguments");

    device = ped_device_get(argv[1]);
    if(device == NULL)
        return -1;

    type = ped_disk_type_get(argv[2]);
    if(type == NULL)
    {
        ped_device_destroy(device);
        error(EXIT_FAILURE, 0, "invalid type");
        return -1;
    }

    disk_old = ped_disk_new(device);
    printf("disk type: %s \n",disk_old->type->name);
    disk = ped_disk_new_fresh(device, disk_old->type);
    if(disk == NULL)
    {
        ped_device_destroy(device);
        error(EXIT_FAILURE, 0, "error formating disk");
        return -1;
    }

    if(!ped_disk_commit(disk))
    {
        ped_disk_destroy(disk);
        error(EXIT_FAILURE, 0, "error writing a new partition table");
        return -1;
    }

    ped_disk_destroy(disk);
    ped_device_destroy(device);
    return 0;
}
