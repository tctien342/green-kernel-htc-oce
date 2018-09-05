# AnyKernel2 Ramdisk Mod Script
# osm0sis @ xda-developers

## AnyKernel setup
# begin properties
properties() {
kernel.string=Greencore U Ultra Kernel v2.3
do.devicecheck=0
do.modules=0
do.cleanup=0
do.cleanuponabort=0
device.name1=htc_pmewl
device.name2=htc_pmeuhl
device.name3=htc_pmewhl
device.name4=
device.name5=
} # end properties

# shell variables
block=/dev/block/bootdevice/by-name/boot;
is_slot_device=0;
ramdisk_compression=auto;


## AnyKernel methods (DO NOT CHANGE)
# import patching functions/variables - see for reference
. /tmp/anykernel/tools/ak2-core.sh;


## AnyKernel file attributes
# set permissions/ownership for included ramdisk files
chmod -R 750 $ramdisk/*;
chown -R root:root $ramdisk/*;


## AnyKernel install
dump_boot;

## begin ramdisk changes

# add floppy script
insert_line init.rc "import /init.greencore.rc" before "import /init.environ.rc" "import /init.greencore.rc";

# ramdisk patch
ramdisk_patch;

## end ramdisk changes

write_boot;

## end install
