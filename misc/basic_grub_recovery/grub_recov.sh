mkdir /mnt/fe
mount /dev/nvme0n1p5 -o subvol=root /mnt/fe
mount /dev/nvme0n1p5 -o subvol=home /mnt/fe/home
mount /dev/nvme0n1p1 /mnt/fe/boot

mount /dev --bind /mnt/fe/dev
mount /sys --bind /mnt/fe/sys
mount /proc --bind /mnt/fe/proc


chroot /mnt/fe

#grub2-mkconfig -o /etc/grub2.cfg
#grub2-mkconfig -o /etc/grub2-efi.cfg


#umount /mnt/fe/dev
#umount /mnt/fe/proc
#umount /mnt/fe/sys
#umount /dev/nvme0n1p1
#umount /dev/nvme0n1p5
