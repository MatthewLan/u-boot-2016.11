/*
 *
 * Configuation settings for the SAMSUNG SMDK2440 board.
 *
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_S3C24X0						/* This is a SAMSUNG S3C24x0-type SoC */
#define CONFIG_S3C2440						/* specifically a SAMSUNG S3C2440 SoC */
#define CONFIG_SMDK2440						/* on a SAMSUNG SMDK2440 Board */

#define CONFIG_SYS_TEXT_BASE	0x0

#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH

/* input clock of PLL (the SMDK2440 has 12MHz input clock) */
#define CONFIG_SYS_CLK_FREQ		12000000

#define CONFIG_CMDLINE_TAG					/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

/*
 * Hardware drivers
 */
/* enable DM9000, disable CS8900 */
#if 0
#define CONFIG_CS8900						/* we have a CS8900 on-board */
#define CONFIG_CS8900_BASE		0x19000300
#define CONFIG_CS8900_BUS16					/* the Linux driver does accesses as shorts */

#else
/*
 * JZ2440V3 has DM9000
 *
 * nGCS4 : 0x2000,0000 ~ 0x2800,0000
 * DM9000's CMD <-> LADDR2
 */
#define CONFIG_DRIVER_DM9000
#define CONFIG_DM9000_BASE		0x20000000
#define DM9000_IO				CONFIG_DM9000_BASE
#define DM9000_DATA				(CONFIG_DM9000_BASE + 4)
#endif

/*
 * select serial console configuration
 */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1			1			/* we use SERIAL 1 on SMDK2440 */

/************************************************************
 * USB support (currently only works with D-cache off)
 ************************************************************/
/* Some Macros are defined in configs/smdk2440_defconfig */
#ifdef  CONFIG_USB				/* --- CONFIG_USB --- */
#define CONFIG_USB_OHCI
#define CONFIG_USB_OHCI_S3C24XX
#define CONFIG_DOS_PARTITION
#endif							/* --- CONFIG_USB --- */

/************************************************************
 * RTC
 ************************************************************/
#if 0
#define CONFIG_RTC_S3C24X0
#endif

#define CONFIG_BAUDRATE			115200

/*
 * BOOTP options
 */
#if 0
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#endif

/*
 * Command line configuration.
 */
#define CONFIG_CMD_BSP

#ifdef  CONFIG_RTC_S3C24X0		/* --- CONFIG_RTC_S3C24X0 --- */
#define CONFIG_CMD_DATE			/* RTC */
#endif							/* --- CONFIG_RTC_S3C24X0 --- */

#define CONFIG_CMD_NAND
#define CONFIG_CMD_REGINFO

#define CONFIG_CMDLINE_EDITING

/* autoboot */
#define CONFIG_BOOT_RETRY_TIME		-1
#define CONFIG_RESET_TO_RETRY

#define CONFIG_NETMASK				255.255.255.0
#define CONFIG_IPADDR				10.0.0.110
#define CONFIG_SERVERIP				10.0.0.1
#define CONFIG_ETHADDR				FE:5D:7B:AA:C7:4C

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE		115200			/* speed to run kgdb serial port */
#endif

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP							/* undef to save memory */
#define CONFIG_SYS_CBSIZE			256
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE			(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS			16
#define CONFIG_SYS_BARGSIZE			CONFIG_SYS_CBSIZE

#define CONFIG_SYS_MEMTEST_START	0x30000000		/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x33F00000		/* 63 MB in DRAM */

#define CONFIG_SYS_LOAD_ADDR		0x30800000

/* support additional compression methods */
#define CONFIG_BZIP2
#define CONFIG_LZO
#define CONFIG_LZMA

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS		1				/* we have 1 bank of DRAM */
#define PHYS_SDRAM_1				0x30000000		/* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE			0x04000000		/* 64 MB */

#define PHYS_FLASH_1				0x00000000		/* Flash Bank #0 */

#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

/* if defined, will use LEGACY to detect NOR-Flash */
#if  0
#define CONFIG_SYS_FLASH_LEGACY_1Mx16
#endif

#define CONFIG_SYS_FLASH_CFI
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_FLASH_CFI_LEGACY
#define CONFIG_SYS_FLASH_LEGACY_512Kx16
#define CONFIG_FLASH_SHOW_PROGRESS			45

#define CONFIG_SYS_MAX_FLASH_BANKS			1
#define CONFIG_SYS_FLASH_BANKS_LIST			{ CONFIG_SYS_FLASH_BASE }
#define CONFIG_SYS_MAX_FLASH_SECT			(35)						/* MX29LV160DB */

#if 0							/* --- in NOR Flash --- */
#define CONFIG_ENV_ADDR						(CONFIG_SYS_FLASH_BASE + 0x070000)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_SIZE						0x10000
/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#endif							/* --- in NOR Flash --- */

/*
 * 1. common/Makefile
 * 2. saveenv(): in common/env_nand.c
 */
#if 1							/* --- in NAND Flash --- */
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OFFSET					0x00040000
#define CONFIG_ENV_SIZE						0x20000			/* NAND Flash 块大小(128K)的倍数 */
#define CONFIG_ENV_RANGE					CONFIG_ENV_SIZE	/* 擦除的块大小 */
#endif							/* --- in NAND Flash --- */

/*
 * Size of malloc() pool
 * BZIP2 / LZO / LZMA need a lot of RAM
 */
#define CONFIG_SYS_MALLOC_LEN				(4 * 1024 * 1024)

#define CONFIG_SYS_MONITOR_LEN				(448 * 1024)
#define CONFIG_SYS_MONITOR_BASE				CONFIG_SYS_FLASH_BASE

/*
 * NAND configuration
 */
#ifdef  CONFIG_CMD_NAND
#define CONFIG_NAND_S3C2440
#define CONFIG_SYS_S3C2440_NAND_HWECC
#define CONFIG_SYS_MAX_NAND_DEVICE			1
#define CONFIG_SYS_NAND_BASE				0x4E000000
#endif

/*
 * File system
 */
/* Some Macros are defined in configs/smdk2440_defconfig */
#ifdef  CONFIG_CMD_UBI			/* --- CONFIG_CMD_UBI --- */
#define CONFIG_CMD_UBIFS
#endif							/* --- CONFIG_CMD_UBI --- */


/* in cmd/Makefile */
#define CONFIG_CMD_MTDPARTS
#ifdef  CONFIG_CMD_MTDPARTS		/* --- CONFIG_CMD_MTDPARTS --- */
								/* --- cmd: mtdparts --- */
/* in drivers/mtd/Makefile */
#define CONFIG_MTD_DEVICE
/* in drivers/mtd/Makefile */
/* #define CONFIG_MTD_PARTITIONS */

#define MTDIDS_DEFAULT				"nand0=smdk2440-0"	/* device */
/* need match with linux-kernel */
/* last part : has no ',' */
#define MTDPARTS_DEFAULT			"mtdparts=smdk2440-0:512k(u-boot),"  \
									"128k(params)," \
									"2m(kernel)," \
									"-(rootfs)"
/*******************************************************************
 #: name                size            offset          mask_flags
 0: u-boot              0x00080000      0x00000000      0
 1: params              0x00020000      0x00080000      0
 2: kernel              0x00200000      0x000a0000      0
 3: rootfs              0x0fd60000      0x002a0000      0
 ******************************************************************/
								/* --- cmd: mtdparts --- */

#if 0
#define CONFIG_BOOTARGS			"console=ttySAC0 root=/dev/mtdblock3 rootfstype=jffs2"
#define CONFIG_BOOTCOMMAND		"nand read 30000000 kernel;bootm 30000000"
#endif
#endif							/* --- CONFIG_CMD_MTDPARTS --- */ 

/* support jffs2 */
#ifdef  CONFIG_CMD_NAND			/* --- CONFIG_CMD_NAND --- */

#define CONFIG_CMD_JFFS2
#ifdef  CONFIG_CMD_JFFS2		/* --- CONFIG_CMD_JFFS2 --- */
#define CONFIG_JFFS2_DEV			"nand0"
#define CONFIG_JFFS2_NAND

#if 0	/* use default val */
#define CONFIG_JFFS2_PART_OFFSET	0x00000000	/* default */
#define CONFIG_JFFS2_PART_SIZE		0xFFFFFFFF	/* default */
#endif
#endif							/* --- CONFIG_CMD_JFFS2 --- */
#endif							/* --- CONFIG_CMD_NAND --- */

#define CONFIG_YAFFS2

#if 0
#define CONFIG_RBTREE
#endif

/* additions for new relocation code, must be added to all boards */
#define CONFIG_SYS_SDRAM_BASE				PHYS_SDRAM_1
#define CONFIG_SYS_INIT_SP_ADDR				(CONFIG_SYS_SDRAM_BASE + 0x1000 - GENERATED_GBL_DATA_SIZE)

#define CONFIG_BOARD_EARLY_INIT_F

#endif /* __CONFIG_H */
