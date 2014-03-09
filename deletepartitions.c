#include <error.h>
#include <stdio.h>

#include <parted/parted.h>

int main(int argc, char* argv[])
{
    PedDevice* device;
    PedDisk* disk;

    if(argc != 2)
        error(EXIT_FAILURE, 0, "wrong number of argument");
    
    device = ped_device_get(argv[1]);
    if(device == NULL)
        error(EXIT_FAILURE, 0, "error getting the device");

    disk = ped_disk_new(device);
    if(disk == NULL)
    {
        ped_device_destroy(device);
        error(EXIT_FAILURE, 0, "error getting the disk");
    }

    ped_disk_delete_all(disk);
    
    ped_disk_commit(disk);

    ped_disk_destroy(disk);
    ped_device_destroy(device);

        
    return 0;
}
