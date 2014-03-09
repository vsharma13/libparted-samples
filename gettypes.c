#include <error.h>
#include <stdio.h>

#include <parted/parted.h>

int main(void)
{
    PedDiskType* type = NULL;
    while((type = ped_disk_type_get_next(type)))
    {
        printf("type name: %s\n", type->name);
    }

    return 0;
}
