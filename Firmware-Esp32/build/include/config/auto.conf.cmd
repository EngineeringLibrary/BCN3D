deps_config := \
	/home/arch/esp/esp-idf/components/app_trace/Kconfig \
	/home/arch/esp/esp-idf/components/aws_iot/Kconfig \
	/home/arch/esp/esp-idf/components/bt/Kconfig \
	/home/arch/esp/esp-idf/components/esp32/Kconfig \
	/home/arch/esp/esp-idf/components/ethernet/Kconfig \
	/home/arch/esp/esp-idf/components/fatfs/Kconfig \
	/home/arch/esp/esp-idf/components/freertos/Kconfig \
	/home/arch/esp/esp-idf/components/heap/Kconfig \
	/home/arch/esp/esp-idf/components/log/Kconfig \
	/home/arch/esp/esp-idf/components/lwip/Kconfig \
	/home/arch/esp/esp-idf/components/mbedtls/Kconfig \
	/home/arch/esp/esp-idf/components/openssl/Kconfig \
	/home/arch/esp/esp-idf/components/pthread/Kconfig \
	/home/arch/esp/esp-idf/components/spi_flash/Kconfig \
	/home/arch/esp/esp-idf/components/spiffs/Kconfig \
	/home/arch/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/arch/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/arch/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/arch/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/arch/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/arch/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
