
#!/bin/bash
# https://dgpu-docs.intel.com/driver/client/overview.html

wget -qO - https://repositories.intel.com/gpu/intel-graphics.key | \
  sudo gpg --yes --dearmor --output /usr/share/keyrings/intel-graphics.gpg
echo "deb [arch=amd64,i386 signed-by=/usr/share/keyrings/intel-graphics.gpg] https://repositories.intel.com/gpu/ubuntu jammy client" | \
  sudo tee /etc/apt/sources.list.d/intel-gpu-jammy.list
sudo apt update

sudo apt install -y \
  intel-opencl-icd intel-level-zero-gpu level-zero \
  intel-media-va-driver-non-free libmfx1 libmfxgen1 libvpl2 \
  libegl-mesa0 libegl1-mesa libegl1-mesa-dev libgbm1 libgl1-mesa-dev libgl1-mesa-dri \
  libglapi-mesa libgles2-mesa-dev libglx-mesa0 libigdgmm12 libxatracker2 mesa-va-drivers \
  mesa-vdpau-drivers mesa-vulkan-drivers va-driver-all vainfo hwinfo clinfo

# If you face issues
# sudo dpkg -i --force-overwrite /var/cache/apt/archives/libglx0_1.7.0-2101~22.04_amd64.deb
# sudo dpkg -i --force-overwrite /var/cache/apt/archives/libgl1_1.7.0-2101~22.04_i386.deb
# sudo dpkg -i --force-overwrite /var/cache/apt/archives/libglvnd0_1.7.0-2101~22.04_i386.deb
# sudo apt --fix-broken install
# sudo apt autoremove

# If you need Steam
# sudo dpkg --add-architecture i386
# sudo apt update
# sudo apt install  -y \
#  udev mesa-va-drivers:i386 mesa-common-dev:i386 mesa-vulkan-drivers:i386 \
#  libd3dadapter9-mesa-dev:i386 libegl1-mesa:i386 libegl1-mesa-dev:i386 \
#  libgbm-dev:i386 libgl1-mesa-glx:i386 libgl1-mesa-dev:i386 \
#  libgles2-mesa:i386 libgles2-mesa-dev:i386 libosmesa6:i386 \
#  libosmesa6-dev:i386 libwayland-egl1-mesa:i386 libxatracker2:i386 \
#  libxatracker-dev:i386 mesa-vdpau-drivers:i386 libva-x11-2:i386

# one api:
# https://www.intel.com/content/www/us/en/docs/oneapi-base-toolkit/get-started-guide-linux/2024-0/before-you-begin.html
# vim /etc/default/grub
# i915.enable_hangcheck=0
# sudo update-grub
# reboot
# stat -c "%G" /dev/dri/render*
# sudo gpasswd -a ${USER} video
# newgrp video


