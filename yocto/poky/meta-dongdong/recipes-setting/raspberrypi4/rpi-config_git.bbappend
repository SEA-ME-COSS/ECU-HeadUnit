# Setting for i2c
# ENABLE_I2C = "1"
# KERNEL_MODULE_AUTOLOAD:rpi += "i2c-dev i2c-bcm2708"
RPI_EXTRA_CONFIG = " \n\
                    dtparam=i2c1=on \n\
                    dtparam=i2c_arm=on \n\
                    dtoverlay=vc4-fkms-v4d-pi4 \n\
                    "

# Setting for SPI
# ENABLE_SPI_BUS = "1"
RPI_EXTRA_CONFIG = " dtparam=spi=on \n"

# Setting for 2-CH CAN HAT
RPI_EXTRA_CONFIG = " \n\
dtoverlay=spil-3cs \n\
dtoverlay=mcp251xfd,spi0-0,interrupt=25 \n\
dtoverlay=mcp251xfd,spi1-0,interrupt=24 \n\
"
# Setting for 2-CH CAN
# ENABLE_CAN = "1"

