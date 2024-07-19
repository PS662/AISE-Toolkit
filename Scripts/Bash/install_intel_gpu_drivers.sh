
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


# one api:
# https://www.intel.com/content/www/us/en/docs/oneapi-base-toolkit/get-started-guide-linux/2024-0/before-you-begin.html
# vim /etc/default/grub
# i915.enable_hangcheck=0
# If needed: 
# i915.request_timeout_ms=200000
# sudo update-grub
# reboot
# stat -c "%G" /dev/dri/render*
# sudo gpasswd -a ${USER} video
# newgrp video


