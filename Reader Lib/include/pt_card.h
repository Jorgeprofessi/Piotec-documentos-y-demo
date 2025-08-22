/**
 * \mainpage
 *
 * \section intro_sec PT系列读写器驱动接口使用说明
 *
 *
 * \subsection 平台支持
 *	
 * -----------------------------------------------------
 *  系统平台           		    |   驱动库名称
 * -----------------------------|-----------------------
 *  Windows          		    |   pt_card.dll
 *  Linux(X86)       		    |   libpt_card.so
 *  Linux(embedded/contact)  	|   libpt_card.so
 *  Linux(embedded/contactless) |   libpt_card.so
 *  
 *
 * \subsection 协议支持
 * -------------------------------------
 *  卡片类型     |   协议类型
 * --------------|-----------------------
 *  接触类卡片   |   ISO7816 \n I2C \n SPI
 *  非接触类卡片 |   ISO14443A \n ISO14443B \n ISO15693 \n MIFARE \n FELICA
 *
 * \subsection 如何使用驱动库
 *
 * 使用驱动库必须包含以下头文件:
 * \code
 * #include "pt_card.h"
 * \endcode
 * 
 * \par 使用接触类卡片的通信应符合以下顺序
 * 标有*的操作是可选的:				\n
 * 1.打开卡片对象:\code card_open \endcode
 * 2.卡片上电电压设置:\code card_setvcc \endcode
 * 3.*卡片时钟频率设置:\code card_setfreq \endcode
 * 4.*卡片的配置参数:\code card_cfg \endcode
 * 5.卡片上电并复位:\code card_reset \endcode
 * 7.*PPS命令:\code card_pps \endcode
 * 8.数据交换命令:\code card_pipe \endcode
 * 9.卡片下电:\code card_off \endcode
 * 10.关闭卡片对象:\code card_close \endcode
 *
 * \par 使用非接触类卡片的通信应符合以下顺序
 * 标有*的操作是可选的：				\n
 * 1.打开卡片对象:\code card_open \endcode
 * 2.*卡片时钟频率设置:\code card_setfreq \endcode
 * 3.*卡片的配置参数:\code card_cfg \endcode
 * 4.卡片上电并复位:\code card_reset \endcode
 * 5.*PPS命令:\code card_pps \endcode
 * 6.数据交换命令:\code card_pipe \endcode
 * 7.卡片下电:\code card_off \endcode
 * 8.关闭卡片对象:\code card_close \endcode
 *
 * \author	Xiaofan.Feng
 * \version
 * \copyright	Piotec
 */

/**
 * \page 错误码
 * \brief 函数返回值说明
 *
 * \section 无错误
 *
 * -------------------------------------
 *    错误码     |        说明
 * --------------|-----------------------
 *	  0x0000	 |       无错误
 * 
 * \section 接触读写器错误码
 *
 * -------------------------------------
 *    错误码     |        说明
 * --------------|-----------------------
 *	   0x1001	 |		无效的电压参数
 *	   0x1002	 |		上电中断 
 *	   0x1003	 |		ATR超时
 *	   0x1004	 |		无效的ATR值
 *	   0x1005	 |		ATR校验失败
 *	   0x1006	 |		协议不支持
 *	   0x1007	 |		无效的SLOT
 *	   0x1008	 |		接收数据超时
 *	   0x1009	 |		接收数据奇偶校验失败 
 *	   0x1010	 |		接收LRC失败
 *	   0x1011	 |		接收CRC失败
 *	   0x1012	 |		接收序号错误
 *	   0x1013	 |		设置IFSD失败
 *	   0x1014	 |		热复位错误
 *	   0x1015	 |		非法的状态字节
 *	   0x1016	 |		未知的错误
 *	   0x1017	 |		块等待超时
 *	   0x1018	 |		字符等待超时
 *	   0x1019	 |		T1协议终止传输错误
 *	   0x1020	 |		超过最大重试次数
 *	   0x1021	 |		无效的NAD
 *	   0x1022	 |		无效的的长度
 *	   0x1023	 |		无效的信息
 *	   0x1024	 |		无效的工作模式
 *	   0x1025	 |		无效的等级
 *	   0x1026	 |		未知的控制命令
 *	   0x1027	 |		不支持PPS交换
 *	   0x1028	 |		未选择SLOT模式
 *	   0x1029	 |		工作模式错误
 *	   0x1030	 |		上电模式错误
 *	   0x1031	 |		电压错误
 *	   0x1032	 |		卡片类型错误
 *	   0x1033	 |		协议错误
 *	   0x1034	 |		PPS模式错误
 *	   0x1035	 |		接收数据溢出
 *	   0x1036	 |		发送数据超时
 *	   0x1037	 |		无效参数
 *	   0x1038	 |		设备忙
 *	   0x1039	 |		获取用户数据失败
 *	   0x1040	 |		返回用户数据失败
 *	   0x1041	 |		设置频率失败
 *	   0x1042	 |		设置WWT失败
 *	   0x1043	 |		设置忽略SW失败
 *	   0x1044	 |		开短路测试失败
 *	   0x1045    |      功能未授权
 *
 * \section 非接触读写器错误码
 *
 * -------------------------------------
 *    错误码     |        说明
 * --------------|-----------------------
 *	  0x2001	 |		接收数据无应答超时
 *	  0x2002	 |		CRC或奇偶校验错误
 *	  0x2003	 |		发生碰撞
 *	  0x2004	 |		缓存溢出
 *	  0x2005	 |		无效的帧格式
 *	  0x2006	 |		应答违反协议
 *	  0x2007	 |		验证失败
 *	  0x2008	 |		内存读写错误
 *	  0x2009	 |		RC温度过热
 *	  0x2010	 |		RF错误
 *	  0x2011	 |		RC通信错误
 *	  0x2012	 |		长度错误
 *	  0x2013	 |		设备资源错误
 *	  0x2014	 |		发送端NAK错误
 *	  0x2015	 |		接收端NAK错误
 *	  0x2016	 |		外部RF错误
 *	  0x2017	 |		EMVCo EMD噪声错误
 *	  0x2018	 |		忽略错误
 *	  0x2019	 |		外部错误
 *	  0x2020	 |		无效的数据参数
 *	  0x2021	 |		无效参数
 *	  0x2022	 |		读写参数溢出
 *	  0x2023	 |		参数不支持
 *	  0x2024	 |		命令不支持
 *	  0x2025	 |		条件不支持
 *	  0x2026	 |		KEY错误
 *	  0x2027	 |		初始化错误
 *
 * \section 应用层错误码
 *
 * -------------------------------------
 *    错误码     |        说明
 * --------------|-----------------------
 *	  0x3001	 |		设备已打开
 *	  0x3002	 |		打开设备失败
 *	  0x3003	 |		关闭设备失败
 *	  0x3004	 |		IP错误
 *	  0x3005	 |		功能不支持
 *	  0x3006	 |		协议不支持
 *	  0x3007	 |		参数错误
 *	  0x3008	 |		文件已存在
 *	  0x3009	 |		打开文件失败
 *	  0x3010	 |		读取文件失败
 *	  0x3011	 |		写入文件失败
 *	  0x3012	 |		检测MD5值失败
 *	  0x3013	 |		读写器型号错误
 *
 * \section 通信层错误码
 *
 * -------------------------------------
 *    错误码     |        说明
 * --------------|-----------------------
 *	  0x4001	 |		未知通信错误
 *	  0x4002	 |		IP地址为空
 *	  0x4003	 |		通信连接未打开
 *	  0x4004	 |		通信连接打开失败
 *	  0x4005	 |		通信连接初始化失败
 *	  0x4006	 |		通信连接关闭失败
 *	  0x4007	 |		通信连接中断
 *	  0x4008	 |		通信连接超时
 *	  0x4009	 |		发送数据失败
 *	  0x4010	 |		接收数据失败
 *	  0x4011	 |		数据命令不支持
 *	  0x4012	 |		内存错误
 *	  0x4013	 |		CRC校验失败
 *	  0x4014	 |		未知应答
 *	  0x4015	 |		应答数据长度错误
 *	  0x4016	 |		网络断开
 *	  0x4017	 |		参数错误
 *	  0x4018	 |		通信连接已打开
 *
 */

/**
 * \page 内部写卡说明
 * \brief 介绍如何使用内部写卡函数实现写卡操作
 *
 * \section 内部写卡使用流程
 * \brief 内部写卡需使用脚本文件和解析脚本库程序文件，将脚本文件和解析库程序保存至读写器内部，然后调用内部写卡接口函数实现读写器内部写卡功能。
 * \see ea_card_connect 连接读写器\n ea_card_disconnect 断开读写器\n ea_card_addpre 下载内部写卡脚本文件接口函数\n ea_card_addpre 下载内部解析脚本库接口函数\n ea_card_initpre 初始化内部写卡接口函数\n ea_card_runpre 运行内部写卡接口函数\n ea_card_exitpre 退出内部写卡接口函数\n
 * \par 使用示例
 * \code
 *  #include "pt_card.h"
 *  card_obj_t obj;
 *
 *  ea_card_connect(&obj, "192.168.1.1");
 *  ea_card_addpre(&obj, ...框架函数库路径, ...框架函数库保存名称, md5, 1);
 *  ea_card_addscript(&obj, ...脚本文件路径, ...脚本文件保存名称, md5, 1);
 *  ea_card_initpre(&obj, ...框架函数库保存名称, ...脚本文件保存名称, ...);
 *  while (job_count) {	//重复调用写卡
 *		ea_card_runpre(&obj, ...);
 *	}
 *  ea_card_exitpre(&obj);
 *  ea_card_disconnect(&obj);
 * \endcode
 *
 * \section 解析脚本库程序
 * \brief 解析脚本库程序提供接口函数实现内部调用，接口函数只提供函数定义，接口函数参数由“运行内部写卡接口函数”的参数传入，接口函数功能需用户自行开发实现。
 * \subsection 接口函数定义
 * \code
 * 	Uint16_t ua_card_initpre(const uint8_t *script_path, const uint8_t *user_data, const uint32_t user_data_len, uint8_t *output_info, uint32_t *output_info_len)
 * \endcode
 * \brief 数据初始化函数，写卡前初始化数据及解析脚本。
 * \param[in]	script_path	脚本路径，内部调用自动传入。
 * \param[in]	user_data 用户数据缓存，由ea_card_initpre传入。
 * \param[in]	user_data_len	用户数据缓存长度，由ea_card_initpre传入
 * \param[in]	output_info 输出信息缓存，由ea_card_initpre传入，函数执行完成返回。
 * \param[in]	output_info_len	输出信息缓存长度，由ea_card_initpre传入最大长度，函数执行完成返回实际长度。
 * \retval		0为成功，其他值为失败(可用户自定义)
 * \note 使用接口函数ea_card_initpre内部调用ua_card_initpre
 *
 * \code
 * 	Uint16_t ua_card_runpre(const uint8_t *user_data, const uint32_t user_data_len, uint8_t *output_info, uint32_t *output_info_len)
 * \endcode
 * \brief 数据执行函数，执行写卡操作流程。
 * \param[in]	user_data 用户数据缓存，由ea_card_runpre传入。
 * \param[in]	user_data_len	用户数据缓存长度，由ea_card_runpre传入
 * \param[in]	output_info 输出信息缓存，由ea_card_runpre传入，函数执行完成返回。
 * \param[in]	output_info_len	输出信息缓存长度，由ea_card_runpre传入最大长度，函数执行完成返回实际长度。
 * \retval		0为成功，其他值为失败(可用户自定义)
 * \note 使用接口函数ea_card_runpre内部调用ua_card_runpre
 *
 * \code
 * 	Uint16_t ua_card_exitpre(uint8_t *output_info, uint32_t *output_info_len)
 * \endcode
 * \brief 数据释放函数，释放数据及设备资源。
 * \param[in]	output_info 输出信息缓存，由ea_card_exitpre传入，函数执行完成返回。
 * \param[in]	output_info_len	输出信息缓存长度，由ea_card_exitpre传入最大长度，函数执行完成返回实际长度。
 * \retval		0为成功，其他值为失败(可用户自定义)
 * \note 使用接口函数ea_card_exitpre内部调用ua_card_exitpre
 *
 * \subsection 解析脚本库实现示例
 * \code
 * #include <stdio.h>
 * #include "pt_card.h"
 * char **script_data = NULL;
 * int script_data_len = 0;
 *
 * Uint16_t ua_card_initpre(const uint8_t *script_path, const uint8_t *user_data, const uint32_t user_data_len, uint8_t *output_info, uint32_t *output_info_len)
 * {
 *	   FILE *fp;
 *	   char line[BUFF_SIZE];
 *
 *	   fp = open(script_path, "r");
 *	   ...
 *	   script_data_len = get_script_wc(...); //获取文件行数
 *	   ...
 *	   script_data = (char **)malloc(script_data_len * sizeof(char *));
 *	   ...
 *	   while (fgets(line, sizeof(line) - 1, fp) != NULL) {
 *		   script_data[i] = (char *)malloc(strlen(line) * sizeof(char) + 1);
 *		   ...
 *	       if (...vcc)
 *		        // 保存数据至script_data[i]
 *		   else if (...pps)
 *		        // 保存数据至script_data[i]
 *		   else if (...freq)
 *		        // 保存数据至script_data[i]
 *		   else
 *		        // 保存数据至script_data[i]
 *	   }
 *	   fclose(fp);
 *     return 0;
 * }
 *
 * Uint16_t ua_card_runpre(const uint8_t *user_data, const uint32_t user_data_len, uint8_t *output_info, uint32_t *output_info_len)
 * {
 *	   card_obj_t obj;
 *	   obj = card_open(&obj, MODEL_P7816, NULL);
 *	   ...
 *	   for (i = 0 i < script_data_len; i++) {
 *	       if (script_data[i]...vcc) {
 *		       card_setvcc(&obj, ...);
 *		   } else if (script_data[i]...pps) {
 *		       card_pps(&obj, ...);
 *		   } else if (script_data[i]...freq) {
 *		       card_setfreq(&obj, ...);
 *		   } else {
 *	           ...data //使用用户数据data处理写卡数据		   
 *		       card_pipe(&obj, ...);
 *		   }
 *	   }
 *	   card_off(&obj);
 *	   card_close(&obj);
 *     return 0;
 * }
 *
 * Uint16_t ua_card_exitpre(uint8_t *output_info, uint32_t *output_info_len)
 * {
 *	   for (i = 0; i < script_data_len; i++) {
 *	       free(script_data[i]);
 *	       script_data[i] = NULL;
 *	   }
 *	   free(script_data);
 *	   script_data = NULL;
 *	   return 0;
 * }
 * \endcode
 * \note 解析脚本库程序调用card_open时，IP地址传入NULL。
 *
 * \subsection 解析脚本库编译
 * \brief 解析脚本库需要通过ARM-LINUX交叉编译
 * \par 编译命令如下:
 * \code
 *  根据编译环境自行替换“[]”内容
 *	arm-linux-gcc -fPIC -L[Embedd接触/非接触库路径libpt_card.so] -I[pt_card.h路径] -shared -o [生成解析脚本库文件名].so 解析脚本库源文件.c -lpt_card
 * \endcode
 *
 */

/**
 * \file	pt_card.h
 * \brief	PT系列读写器接口函数
 * \details	目前接口实现为非接触和接触读写器相关操作
 */
#ifndef _PT_CARD_H_
#define _PT_CARD_H_

/**\addtogroup 宏定义
 *  \{
 */
/* IP地址最大长度 */
#define MAX_ADDR_SIZE	16	/**< IP地址最大长度 */
/* ATR数据最大长度 */
#define ATR_DATA_LEN	255	/**< ATR数据最大长度 */
/* 默认超时时间 */
#define CARD_DEFAULT_TIMEOUT	30000 /**< 默认超时时间 */
/* 基本错误编码 */
#define CARD_NO_ERR		0x0000	/**< 无错误 */

/* 非接触14443A/B卡片通信速率 */
#define CARD_14443_DATARATE_106	0x00U /**< 非接触14443A/B卡片通信速率106 kBit/s */
#define CARD_14443_DATARATE_212	0x01U /**< 非接触14443A/B卡片通信速率212 kBit/s */
#define CARD_14443_DATARATE_424	0x02U /**< 非接触14443A/B卡片通信速率424 kBit/s */
#define CARD_14443_DATARATE_848	0x03U /**< 非接触14443A/B卡片通信速率848 kBit/s */
/* MIFARE卡密钥类型 */
#define CARD_MIFARE_KEYA	0x0AU	/**< A类密钥 */
#define CARD_MIFARE_KEYB	0x0BU	/**< B类密钥 */
/* 非接触卡片配置掩码 */
#define CARD_PICC_CONFIG_MASK_FSDI			0x00000001
#define CARD_PICC_CONFIG_MASK_FWI			0x00000002
#define CARD_PICC_CONFIG_MASK_FWT			0x00000004
#define CARD_PICC_CONFIG_MASK_DRI			0x00000008
#define CARD_PICC_CONFIG_MASK_DSI			0x00000010
#define CARD_PICC_CONFIG_MASK_DS			0x00000020
#define CARD_PICC_CONFIG_MASK_DR			0x00000040
#define CARD_PICC_CONFIG_MASK_SOF			0x00000080
#define CARD_PICC_CONFIG_MASK_EOF			0x00000100
#define CARD_PICC_CONFIG_MASK_EGT			0x00000200
#define CARD_PICC_CONFIG_MASK_FRAME_FLAG	0x00000400
#define CARD_PICC_CONFIG_MASK_SYSTEM_CODE	0x00000800
#define CARD_PICC_CONFIG_MASK_NAD	        0x00001000
#define CARD_PICC_CONFIG_MASK_CID		    0x00002000
#define CARD_PICC_CONFIG_MASK_FSCI			0x00004000
#define CARD_PICC_CONFIG_MASK_RFON_WAIT		0x00008000
#define CARD_PICC_CONFIG_MASK_RFOFF_WAIT	0x00010000
#define CARD_PICC_CONFIG_MASK_AFDT			0x00020000
#define CARD_PICC_CONFIG_MASK_ERR_REEMIT	0x00040000
#define CARD_PICC_CONFIG_MASK_SFGI			0x00080000
#define CARD_PICC_CONFIG_MASK_SFGT			0x00100000
#define CARD_PICC_CONFIG_MASK_AFI			0x00200000
#define CARD_PICC_CONFIG_MASK_SLOT_NO		0x00400000
#define CARD_PICC_CONFIG_MASK_TR0TR1		0x00800000
#define CARD_PICC_CONFIG_MASK_AFWT			0x01000000
#define CARD_PICC_CONFIG_MASK_ASFGT			0x02000000
#define CARD_PICC_CONFIG_MASK_ALL			0xFFFFFFFF
/* 接触卡片配置掩码 */
#define CARD_ICC_CONFIG_MASK_N				0x00000001
#define CARD_ICC_CONFIG_MASK_WWT			0x00000002
#define CARD_ICC_CONFIG_MASK_CWT			0x00000004
#define CARD_ICC_CONFIG_MASK_BWT			0x00000008
#define CARD_ICC_CONFIG_MASK_NAD			0x00000010
#define CARD_ICC_CONFIG_MASK_IFSC			0x00000020
#define CARD_ICC_CONFIG_MASK_TSWT			0x00000040
#define CARD_ICC_CONFIG_MASK_TSWWT			0x00000080
#define CARD_ICC_CONFIG_MASK_RSTWT			0x00000100
#define CARD_ICC_CONFIG_MASK_T1RETIES		0x00000200
#define CARD_ICC_CONFIG_MASK_PPSGT			0x00000400
#define CARD_ICC_CONFIG_MASK_AUTO_RESP		0x00000800
#define CARD_ICC_CONFIG_MASK_AUTO_RELE		0x00001000
#define CARD_ICC_CONFIG_MASK_AUTO_PPS		0x00002000
#define CARD_ICC_CONFIG_MASK_WWT_MS			0x00004000
#define CARD_ICC_CONFIG_MASK_COMM_PROT		0x00008000
#define CARD_ICC_CONFIG_MASK_ALL			0xFFFFFFFF
/* 开短路测试引脚参考点定义 */
#define CARD_OSTEST_REF_C1			0x01
#define CARD_OSTEST_REF_C2			0x02
#define CARD_OSTEST_REF_C3			0x03
#define CARD_OSTEST_REF_C4			0x04
#define CARD_OSTEST_REF_C5			0x05
#define CARD_OSTEST_REF_C6			0x06
#define CARD_OSTEST_REF_C7			0x07
#define CARD_OSTEST_REF_C8			0x08
/* 开短路测试引脚测试点定义 */
#define CARD_OSTEST_PINS_BIT_C1		0x01
#define CARD_OSTEST_PINS_BIT_C2		0x02
#define CARD_OSTEST_PINS_BIT_C3		0x04
#define CARD_OSTEST_PINS_BIT_C4		0x08
#define CARD_OSTEST_PINS_BIT_C5		0x10
#define CARD_OSTEST_PINS_BIT_C6		0x20
#define CARD_OSTEST_PINS_BIT_C7		0x40
#define CARD_OSTEST_PINS_BIT_C8		0x80
#define CARD_OSTEST_PINS_BIT_ALL	0xFF

/**
 *  \}
 */
/**\addtogroup 数据类型定义
 *  \{
 */
/* 数据类型 */
typedef unsigned char Uint8_t;		/**< 1字节无符号数据类型 */
typedef unsigned short Uint16_t;	/**< 2字节无符号数据类型 */
typedef unsigned long Uint32_t;		/**< 4字节无符号数据类型 */
typedef long Int32_t;				/**< 4字节有符号数据类型 */
typedef Uint16_t card_err_t;		/**< 错误码数据类型 */
/**
 *  \}
 */

/**\addtogroup 卡片类型定义
 *  \{
 */
/* 卡片模式 */
/** 卡片模式 */
typedef enum card_model {
	MODEL_NULL = 0x00,			/**< 未定义 */
	MODEL_P14443A = 0x01,		/**< 非接触ISO14443A协议 */
	MODEL_P14443B =	0x02,		/**< 非接触ISO14443B协议 */
	MODEL_PMIFARE = 0x03,		/**< 非接触MIFARE协议 */
	MODEL_PFELICA =	0x04,		/**< 非接触FELICA协议 */
	MODEL_P15693 =	0x05,		/**< 非接触ISO15693协议 */
	MODEL_P7816 = 0x06,			/**< 接触ISO7816协议 */
	MODEL_P7816_SYNC = 0x07,	/**< 接触ISO7816协议(同步卡) */
	MODEL_PI2C = 0x08,			/**< 接触I2C协议 */
	MODEL_PSPI = 0x09,			/**< 接触SPI协议 */
	MODEL_PUART = 0x0A,			/**< 接触UART协议 */
	MODEL_PSWD = 0x0B,			/**< 接触SWD协议 */
} card_mod_t;
/**
 *  \}
 */

/* 卡片对象结构体 */
/** 卡片对象结构体 */
typedef struct card_object {
	Int32_t handle;					/**< 卡片对象句柄 */
	Uint8_t addr[MAX_ADDR_SIZE];	/**< 卡片对象地址 */
	card_mod_t	model;				/**< 卡片模式 */
	Uint8_t atr[ATR_DATA_LEN];		/**< 卡片ATR值 */
	Uint8_t atr_len;				/**< 卡片ATR长度 */
	Uint8_t sw1;					/**< 卡片返回值SW1 */
	Uint8_t sw2;					/**< 卡片返回值SW2 */
	Uint32_t timeout;				/**< 通信超时时限 */
	card_err_t	last_err;			/**< 最后出错错误编号 */
} card_obj_t;

/* 接触卡片配置结构体 */
/** 接触卡片配置结构体 */
#ifdef WIN32
#pragma pack(1)
#endif
typedef struct card_icc_config {
	Uint32_t mask;			/**< 标记掩码 */
	Uint8_t n;				/**< 额外等待时间 */
	Uint32_t wwt;			/**< 工作等待时间 T0协议 单位ETU */
	Uint32_t cwt;			/**< 字符等待时间 T1协议 */
	Uint32_t bwt;			/**< 块等待时间 T1协议 */
	Uint8_t nad;			/**< 节点地址 T1协议 */
	Uint8_t ifsc;			/**< 最大段长度 T1协议 只读 */
	Uint32_t tswt;			/**< 接收ATR TS字节前等待时间 */
	Uint32_t tswwt;			/**< 接收ATR TS字节工作等待时间 */
	Uint16_t rstwt;			/**< 复位等待时间 单位 毫秒 */
	Uint8_t t1reties;		/**< 重试次数 T1协议 */
	Uint16_t ppsgt;			/**< PPS等待时间 单位 毫秒 */
	Uint8_t auto_resp;		/**< SW1=0x61 自动应答开关 */
	Uint8_t auto_rele;		/**< SW1=0x6C 自动重发Le开关 */
	Uint8_t auto_pps;		/**< 自动PPS开关 */
	Uint16_t wwt_ms;		/**< 工作等待时间 T0协议 单位毫秒 基于wwt */
	Uint8_t comm_prot;		/**< 通信协议 */
#ifdef WIN32
} card_cfg_t;
#pragma pack()
#else
} __attribute__((packed)) card_cfg_t;
#endif

/* 非接触卡片配置结构体 */
/** 非接触卡片配置结构体 */
#ifdef WIN32
#pragma pack(1)
#endif
typedef struct card_picc_config {
	Uint32_t mask;			/** 标记掩码 */
	Uint8_t fsdi;
	Uint8_t fwi;
	Uint32_t fwt;
	Uint8_t dri;
	Uint8_t dsi;
	Uint8_t ds;
	Uint8_t dr;
	Uint16_t sof;
	Uint8_t eof;
	Uint8_t egt;
	Uint32_t frame_flag;
	Uint16_t system_code;	/**< Felica轮询指令使用 默认0xFFFF */
	Uint8_t nad;
	Uint8_t cid;
	Uint8_t fsci;
	Uint16_t rfon_wait;		/**< RF开启后等待时间(微妙) */
	Uint16_t rfoff_wait;	/**< RF关闭后等待时间(微妙) */
	Uint32_t afdt;
	Uint8_t err_reemit;
	Uint8_t sfgi;
	Uint32_t sfgt;
	Uint8_t afi;
	Uint8_t slot_no;
	Uint16_t tr0tr1;
	Uint32_t afwt;
	Uint32_t asfgt;
#ifdef WIN32
} card_pcfg_t;
#pragma pack()
#else
} __attribute__((packed)) card_pcfg_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------------------------------------
			接触和非接触读写器通用接口函数
 ---------------------------------------------------------*/
/**\addtogroup 接触和非接触通用接口函数
 *  \{
 */

/**
 * \brief		通过读写器IP地址，初始化卡片通信对象和通信模式。
 * \callgraph
 * \param[in]	obj 卡片对象结构体
 * \param[in]	model 卡片模式
 * \param[in]	addr IP地址，如"192.168.1.1"
 * \retval		CARD_NO_ERR 成功
 * \note		任何操作前必须调用此函数。
 */
card_err_t card_open(card_obj_t *obj, card_mod_t model, Uint8_t *addr);
/**
 * \brief		关闭读写器，释放资源。
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 * \note		操作结束后必须调用此函数。
 */
card_err_t card_close(card_obj_t *obj);
/**
 * \brief		获取读写器设备信息。
 *				目前设备信息为版本号。
 * \param[in]	obj 卡片对象结构体
 * \param[out]	info 设备信息，字符长度64字节。
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_getinfo(card_obj_t *obj, Uint8_t *info);
/**
 * \brief		获取读写器设备权限信息。
 * \param[in]	obj 卡片对象结构体
 * \param[out]	info 权限信息，字符长度10字节。
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_getpermissioninf(card_obj_t *obj, Uint8_t *inf);
/**
 * \brief		卡片复位
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 * \note		接触读写器为冷复位
 */
card_err_t card_reset(card_obj_t *obj);
/**
 * \brief		卡片下电
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 * \note		非接触读写器为关闭载波磁场
 */
card_err_t card_off(card_obj_t *obj);
/**
 * \brief		设置读写器频率
 * \param[in]	obj 卡片对象结构体
 * \param[in]	freq 频率数值
 * \retval		CARD_NO_ERR 成功
 * \note		频率单位KHz,分辨率100KHz
 */
card_err_t card_setfreq(card_obj_t *obj, Uint16_t freq);
/**
 * \brief		获取读写器频率
 * \param[in]	obj 卡片对象结构体
 * \param[out]	freq 频率数值
 * \retval		CARD_NO_ERR 成功
 * \note		频率单位KHz,分辨率10KHz,范围1000-20000KHz,默认3570KHz
 */
card_err_t card_getfreq(card_obj_t *obj, Uint16_t *freq);
/**
 * \brief		接触读写器为协议和参数选择设置
 *				非接触读写器为通信速率设置
 * \param[in]	obj 卡片对象结构体
 * \param[in]	param1 接触读写器PPS0数值
 *					   非接触读写器DRI数值
 * \param[in]	param2 接触读写器PPS1数值
 *					   非接触读写器DSI数值
 * \retval		CARD_NO_ERR 成功
 * \note		非接触读写器DRI/DSI数值在宏READER_DATARATE_XXX中定义
 */
card_err_t card_pps(card_obj_t *obj, Uint8_t param1, Uint8_t param2);
/**
 * \brief		读写器与卡片进行数据交换
 * \param[in]	obj 卡片对象结构体
 * \param[in]	tbuf 发送数据缓存
 * \param[in]	tlen 发送数据长度
 * \param[out]	rbuf 接收数据缓存
 * \param[out]	rlen 接收数据长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_pipe(card_obj_t *obj, Uint8_t *tbuf, Uint16_t tlen, Uint8_t *rbuf, Uint16_t *rlen);
/**
 *  \}
 */
/*---------------------------------------------------------
 					接触读写器接口
 ---------------------------------------------------------*/
/**\addtogroup 接触接口函数
 *  \{
 */
/**
 * \brief		设置VCC电压
 * \param[in]	obj 卡片对象结构体
 * \param[in]	vcc 卡片电压值
 * \retval		CARD_NO_ERR 成功
 * \note		vcc单位为mV,目前只支持1800/3000/5000。
 */
card_err_t card_setvcc(card_obj_t *obj, Uint16_t vcc);
/**
 * \brief		获取VCC电压
 * \param[in]	obj 卡片对象结构体
 * \param[out]	vcc 卡片电压值
 * \retval		CARD_NO_ERR 成功
 * \note		vcc单位为mV,目前只支持1800/3000/5000。
 */
card_err_t card_getvcc(card_obj_t *obj, Uint16_t *vcc);
/**
 * \brief		卡片热复位
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_warm_reset(card_obj_t *obj);
/**
 * \brief		读写器设置ETU
 * \param[in]	obj 卡片对象结构体
 * \param[in]	etu 卡片时钟周期，默认为372
 * \retval		CARD_NO_ERR 成功
 * \note		etu单位为秒,目前只支持设置为372/186/93/31,对应通信波特率为9600/19200/38400/115200。
 */
card_err_t card_etu(card_obj_t *obj, Uint16_t etu);
/**
 * \brief		卡片开短路测试
 * \param[in]	obj 卡片对象结构体
 * \param[in]	vol 测量参考电压设置
 * \param[in]	ref 参考点设置,按位设置引脚参考点
 * \param[in]	pins 测量点设置，按位设置引脚测量点
 * \param[out]	val 测量电压结果
 * \retval		CARD_NO_ERR 成功
 * \note		vol单位为mV,范围0-5000 \n
 *				val单位为mV,数组长度为8
 */
card_err_t card_os_test(card_obj_t *obj, Uint16_t vol, Uint8_t ref, Uint8_t pins, Uint16_t *val);
/**
 * \brief		读取或更新读写器配置参数
 * \param[in]	obj 卡片对象结构体
 * \param[in]	cfg 接触读写器配置结构体
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_cfg(card_obj_t *obj, card_cfg_t *cfg);
/**
 *  \}
 */
/*---------------------------------------------------------
 					非接触读写器接口
 ---------------------------------------------------------*/
/**\addtogroup 非接触通用接口函数
 *  \{
 */
/**
 * \brief		自动选择卡片协议
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 * \note		只支持ISO14443A/B、MIFARE协议自动选择
 */
card_err_t card_automodel(card_obj_t * obj);
/**
 * \brief		卡片协议设置
 * \param[in]	obj 卡片对象结构体
 * \param[in]	model 卡片协议
 * \retval		CARD_NO_ERR 成功
 * \note		只支持非接触协议
 */
card_err_t card_setmodel(card_obj_t *obj, card_mod_t model);
/**
 * \brief		卡片协议获取
 * \param[in]	obj 卡片对象结构体
 * \param[out]   model 卡片协议
 * \retval		CARD_NO_ERR 成功
 * \note        只支持非接触协议
 */
card_err_t card_getmodel(card_obj_t *obj, card_mod_t *model);
/**
 * \brief		开启载波磁场
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 * \note		对应card_off关闭载波磁场
 */
card_err_t card_on(card_obj_t *obj);
/* ISO14443A Level 3 */
/**
 * \brief		执行卡片reqa命令	
 * \param[in]	obj 卡片对象结构体
 * \param[out]	atqa 卡片请求应答
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_reqa(card_obj_t *obj, Uint16_t *atqa);
/**
 * \brief		执行卡片唤醒命令
 * \param[in]	obj 卡片对象结构体
 * \param[out]	atqa 卡片请求应答
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_wupa(card_obj_t *obj, Uint16_t *atqa);
/**
 * \brief		执行防冲突命令
 * \param[in]	obj 卡片对象结构体
 * \param[out]	uid	卡片唯一标识符
 * \param[out]	uid_len 卡片唯一标识符长度
 * \param[out]	sak	选择确认字符
 * \param[out]	status	状态标志
 * \retval		CARD_NO_ERR 成功
 * \note		status: 0 未检测到冲突 \n
 *						1 检测到冲突
 */
card_err_t card_anticol(card_obj_t *obj, Uint8_t *uid, Uint16_t *uid_len, Uint8_t *sak, Uint8_t *status);
/**
 * \brief		执行卡片选择命令
 * \param[in]	obj 卡片对象结构体
 * \param[in]	uid 卡片唯一标识符
 * \param[in]	uid_len 卡片唯一标识符长度
 * \param[out]	sak 选择确认字符
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_select(card_obj_t *obj, Uint8_t *uid, Uint16_t uid_len, Uint8_t *sak);
/**
 * \brief		执行卡片暂停命令
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_halta(card_obj_t *obj);
/* ISO14443A Level 4 */
/**
 * \brief		卡片请求应答选择命令
 * \param[in]	obj 卡片对象结构体
 * \param[out]	ats	卡片请求应答数据
 * \param[out]	ats_len 卡片请求应答数据长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_rats(card_obj_t *obj, Uint8_t *ats, Uint16_t *ats_len);

/* ISO14443B Level 3 */
/**
 * \brief		执行卡片reqb命令
 * \param[in]	obj 卡片对象结构体
 * \param[out]	atqb 卡片请求应答
 * \param[out]	atqb_len 卡片请求应答长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_reqb(card_obj_t *obj, Uint8_t *atqb, Uint8_t *atqb_len);
/**
 * \brief		执行卡片唤醒命令
 * \param[in]	obj 卡片对象结构体
 * \param[out]	atqb 卡片请求应答
 * \param[out]	atqb_len 卡片请求应答长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_wupb(card_obj_t *obj, Uint8_t *atqb, Uint8_t *atqb_len);
/**
 * \brief		执行attrib命令
 * \param[in]	obj 卡片对象结构体
 * \param[out]	rbuf attrib命令应答数据
 * \param[out]	rlen attrib命令应答数据长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_attrib(card_obj_t *obj, Uint8_t *rbuf, Uint16_t *rlen);
/**
 * \brief		执行卡片暂停命令
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_haltb(card_obj_t *obj);
/** ISO14443A/B Level 4 */
/**
 * \brief		取消选择卡片命令
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_deselect(card_obj_t *obj);
/**
 * \brief		检查天线内卡片的存在,R(NAK)块发送,卡片R(ACK)块应答
 * \param[in]	obj 卡片对象结构体
 * \param[out]	val 卡片R(ACK)块应答,1字节
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_getdetect(card_obj_t *obj, Uint8_t *val);

/* ISO14443A/B 配置信息 */
/**
 * \brief		获取卡片标识符
 * \param[in]	obj 卡片对象结构体
 * \param[out]	id	卡片标识符
 * \param[out]	id_len 卡片标识符长度
 * \retval		CARD_NO_ERR 成功
 * \note		ISO14443A id: UID \n
 *				ISO14443B id: PUPI
 */
card_err_t card_getid(card_obj_t *obj, Uint8_t *id, Uint8_t *id_len);
/* ISO14443B 配置信息 */
/**
 * \brief		设置attrib命令高层配置
 * \param[in]	obj 卡片对象结构体
 * \param[in]	tbuf 高层配置信息
 * \param[in]	tlen 高层配置信息长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_setattribinf(card_obj_t *obj, Uint8_t *tbuf, Uint16_t tlen);
/**
 * \brief		获取attrib命令高层配置
 * \param[in]	obj 卡片对象结构体
 * \param[out]  rbuf 高层配置信息
 * \param[out]	rlen 高层配置信息长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_getattribinf(card_obj_t *obj, Uint8_t *rbuf, Uint16_t *rlen);

/* Mifare */
/**
 * \brief		MIFARE卡片认证
 * \param[in]	obj 卡片对象结构体
 * \param[in]	block_no 块编号
 * \param[in]	key_type 密钥类型
 * \param[in]	key	密钥
 * \param[in]	uid	卡片UID
 * \retval		CARD_NO_ERR 成功
 * \note		key_type: CARD_MIFARE_KEYA或CARD_MIFARE_KEYB \n
 *				key: 密钥6字节长度
 */
card_err_t card_authenticate(card_obj_t *obj, Uint8_t block_no, Uint8_t key_type, Uint8_t *key, Uint8_t *uid);
/**
 * \brief		MIFARE卡片读取数据
 * \param[in]	obj 卡片对象结构体
 * \param[in]	block_no 块编号
 * \param[out]	rbuf 块数据，长度16字节
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_mifare_read(card_obj_t *obj, Uint8_t block_no, Uint8_t *rbuf);
/**
 * \brief		MIFARE卡片写入数据
 * \param[in]	obj 卡片对象结构体
 * \param[in]	block_no 块编号
 * \param[in]	tbuf 块数据，长度16字节
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_mifare_read(card_obj_t *obj, Uint8_t block_no, Uint8_t *tbuf);
/* 非接触读写器配置 */
/**
 * \brief		非接触读写器配置设置
 * \param[in]	obj 卡片对象结构体
 * \param[in]	cfg 非接触读写器配置结构体
 * \retval		CARD_NO_ERR 成功
 */
card_err_t card_pcfg(card_obj_t *obj, card_pcfg_t *cfg);
/**
 *  \}
 */
/*---------------------------------------------------------
			内部写卡接口函数
 ---------------------------------------------------------*/
/**\addtogroup 内部写卡接口函数
 *  \{
 */
/**
 * \brief		通过读写器IP地址，连接读写器。
 * \callgraph
 * \param[in]	obj 卡片对象结构体
 * \param[in]	addr IP地址，如"192.168.1.1"
 * \retval		CARD_NO_ERR 成功
 * \note		内部写卡任何操作前必须调用此函数。
 */
card_err_t ea_card_connect(card_obj_t *obj, Uint8_t *addr);
/**
 * \brief		断开读写器，释放资源。
 * \param[in]	obj 卡片对象结构体
 * \retval		CARD_NO_ERR 成功
 * \note		内部写卡操作结束后必须调用此函数。
 */
card_err_t ea_card_disconnect(card_obj_t *obj);
/**
 * \brief		下载内部解析脚本库程序
 * \param[in]	obj 卡片对象结构体
 * \param[in]	path 库程序文件路径
 * \param[in]	name 库程序保存名称
 * \param[out]	md5	下载成功返回库程序MD5值(长度16字节)
 * \param[in]	force 覆盖写入 0:检查文件存在 1:不检测文件存在,覆盖写入
 * \retval		CARD_NO_ERR 成功
 */
card_err_t ea_card_addpre(card_obj_t *obj, Uint8_t *path, Uint8_t *name, Uint8_t *md5, Uint8_t force);

/**
 * \brief		下载内部写卡脚本文件
 * \param[in]	obj 卡片对象结构体
 * \param[in]	path 脚本文件路径
 * \param[in]	name 脚本文件保存名称
 * \param[out]	md5	下载成功返回脚本文件MD5值(长度16字节)
 * \param[in]	force 覆盖写入 0:检查文件存在 1:不检测文件存在,覆盖写入
 * \retval		CARD_NO_ERR 成功
 */
card_err_t ea_card_addscript(card_obj_t *obj, Uint8_t *path, Uint8_t *name, Uint8_t *md5, Uint8_t force);

/**
 * \brief		删除内部解析脚本库程序
 * \param[in]	obj 卡片对象结构体
 * \param[in]	name 库程序名称
 * \retval		CARD_NO_ERR 成功
 * \note		库程序名称可通过获取库程序列表读取
 * \see			ea_card_listpre
 */
card_err_t ea_card_delpre(card_obj_t *obj, Uint8_t *name);

/**
 * \brief		删除内部写卡脚本文件
 * \param[in]	obj 卡片对象结构体
 * \param[in]	name 脚本文件名称
 * \retval		CARD_NO_ERR 成功
 * \note		脚本文件名称可通过获取脚本文件列表读取
 * \see			ea_card_listscript
 */
card_err_t ea_card_delscript(card_obj_t *obj, Uint8_t *name);

/**
 * \brief		列出读写器中存在的库程序名称
 * \param[in]	obj 卡片对象结构体
 * \param[in]	list 库程序名称集合缓存
 * \param[in]	list_len 库程序名称集合缓存长度
 * \param[out]	list_all_len 库程序名称集合实际长度
 * \retval		CARD_NO_ERR 成功
 * \note		库程序名称集合缓存中各个名称以逗号分割，例如"name1,name2,name3"
 */
card_err_t ea_card_listpre(card_obj_t *obj, Uint8_t *list, Uint32_t list_len, Uint32_t *list_all_len);


/**
 * \brief		列出读写器中存在的脚本文件名称
 * \param[in]	obj 卡片对象结构体
 * \param[in]	list 脚本文件名称集合缓存
 * \param[in]	list_len 脚本文件名称集合缓存长度
 * \param[out]	list_all_len 脚本文件名称集合实际长度
 * \retval		CARD_NO_ERR 成功
 * \note		脚本文件名称集合缓存中各个名称以逗号分割，例如"script1,script2,script3"
 */
card_err_t ea_card_listscript(card_obj_t *obj, Uint8_t *list, Uint32_t list_len, Uint32_t *list_all_len);

/**
 * \brief		初始化内部写卡
 * \param[in]	obj 卡片对象结构体
 * \param[in]	pre_name PRE程序名称
 * \param[in]	script_name 脚本文件名称(可为NULL)
 * \param[in]	user_data 用户数据缓存
 * \param[in]	user_data_len 用户数据长度
 * \param[out]	output_info 输出信息缓存
 * \param[out]	output_info_len 输出信息长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t ea_card_initpre(card_obj_t *obj, Uint8_t *pre_name, Uint8_t *script_name, Uint8_t *user_data, Uint32_t user_data_len, Uint8_t *output_info, Uint32_t *output_info_len);

/**
 * \brief		运行内部写卡
 * \param[in]	obj 卡片对象结构体
 * \param[in]	user_data 用户数据缓存
 * \param[in]	user_data_len 用户数据长度
 * \param[out]	output_info 输出信息缓存
 * \param[out]	output_info_len 输出信息长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t ea_card_runpre(card_obj_t *obj, Uint8_t *user_data, Uint32_t user_data_len, Uint8_t *output_info, Uint32_t *output_info_len);

/**
 * \brief		退出内部写卡
 * \param[in]	obj 卡片对象结构体
 * \param[out]	output_info 输出信息缓存
 * \param[out]	output_info_len 输出信息长度
 * \retval		CARD_NO_ERR 成功
 */
card_err_t ea_card_exitpre(card_obj_t *obj, Uint8_t *output_info, Uint32_t *output_info_len);
/**
 *  \}
 */
/*---------------------------------------------------------
			I2C协议写卡接口函数
 ---------------------------------------------------------*/
#define I2C_PARAM_ADDRESS_WIDTH				0x01	/* 0 = 7BIT, 1 = 10BIT default is 0 */
#define I2C_PARAM_IGNORE_NAK				0x02	/* XXX (not support) 0 = off, 1 = on default is 0 */
#define I2C_PARAM_FREQ						0x03	/* 100000(100K)  or 400000(400K) */
#define I2C_PARAM_TIMEOUT					0x04	/* default 1000 (ms )*/
#define I2C_PARAM_ADDRESS_POLLING_TIMEOUT	0X05	/* default 3000 (ms) */
#define I2C_PARAM_ADDRESS_POLLING_INTERVAL	0X06	/* default 1	(ms) */
#define I2C_PARAM_WRITE_READ_INTERVAL		0X07	/* default 5	(ms) */
/**\addtogroup I2C协议写卡接口函数
 *  \{
 */
card_err_t card_i2c_on(card_obj_t *obj, Uint16_t vcc);
card_err_t card_i2c_off(card_obj_t *obj);
card_err_t card_i2c_read(card_obj_t *obj, Uint16_t address, Uint8_t *rbuf, Uint16_t *rlen);
card_err_t card_i2c_write(card_obj_t *obj, Uint16_t address, Uint8_t *tbuf, Uint16_t tlen);
card_err_t card_i2c_write_read(card_obj_t *obj, Uint16_t address, Uint8_t *tbuf, Uint16_t tlen, Uint8_t *rbuf, Uint16_t *rlen);
card_err_t card_i2c_setparam(card_obj_t *obj, Uint8_t type, Uint32_t value);
card_err_t card_i2c_getparam(card_obj_t *obj, Uint8_t type, Uint32_t *value);
card_err_t card_i2c_reset(card_obj_t *obj, Uint32_t value);
card_err_t card_i2c_7816_reset(card_obj_t *obj,Uint16_t address);
card_err_t card_i2c_7816_apdu(card_obj_t *obj,  Uint16_t address,Uint8_t *tbuf, Uint16_t tlen, Uint8_t *rbuf, Uint16_t *rlen);
//card_err_t card_i2c_mi_reset(card_obj_t *obj,Uint16_t address);
//card_err_t card_i2c_mi_apdu(card_obj_t *obj,  Uint16_t address,Uint8_t *tbuf, Uint16_t tlen, Uint8_t *rbuf, Uint16_t *rlen);



/**
 *  \}
 */

/**
 *  \}
 */
/*---------------------------------------------------------
			SPI协议写卡接口函数
 ---------------------------------------------------------*/
#define SPI_PARAM_CONVENTION	0x01	/* 0 = MSB, 1 = LSB */
#define SPI_PARAM_MODE			0x02	/*
										 *  mode is (CPOL|CPHA)
										 *  value 0 = (0|0), 1 = (0|1), 2 = (1|0), 3 = (1|1)
										 *  CPOL 0 = clock low in idle state, 1 = clock high in idle state
										 *	CPHA 0 = sampled on the first clock edge, 1 = sampled on the second clock edge
										 */
#define SPI_PARAM_FREQ			0x03	/* frequency of the signal SCLK (from 1000 000 to 20 000 000) */
/**\addtogroup SPI协议写卡接口函数
 *  \{
 */
card_err_t card_spi_on(card_obj_t *obj, Uint16_t vcc);
card_err_t card_spi_off(card_obj_t *obj);
card_err_t card_spi_read(card_obj_t *obj, Uint8_t *rbuf, Uint16_t *rlen);
card_err_t card_spi_write(card_obj_t *obj, Uint8_t *tbuf, Uint16_t tlen);
card_err_t card_spi_write_read(card_obj_t *obj, Uint8_t *tbuf, Uint16_t tlen, Uint8_t *rbuf, Uint16_t *rlen);
card_err_t card_spi_setparam(card_obj_t *obj, Uint8_t type, Uint32_t value);
card_err_t card_spi_getparam(card_obj_t *obj, Uint8_t type, Uint32_t *value);
card_err_t card_spi_reset(card_obj_t *obj, Uint32_t value);
card_err_t card_spi_7816_reset(card_obj_t *obj);
card_err_t card_spi_7816_apdu(card_obj_t *obj, Uint8_t *tbuf, Uint16_t tlen, Uint8_t *rbuf, Uint16_t *rlen);
/**
 *  \}
 */
 
 
/**\addtogroup SWD协议写卡接口函数
 *  \{
 */

card_err_t card_swd_on(card_obj_t *obj, Uint16_t vcc);
card_err_t card_swd_off(card_obj_t *obj);
card_err_t card_swd_bus_reset(card_obj_t *obj);
card_err_t card_swd_connect(card_obj_t *obj);
card_err_t card_swd_disconnect(card_obj_t *obj);
card_err_t card_swd_clr_error(card_obj_t *obj);
card_err_t card_swd_dap_read(card_obj_t *obj, Uint8_t addr,Uint32_t *rbuf);
card_err_t card_swd_dap_write(card_obj_t *obj, Uint8_t addr,Uint32_t tbuf);
/**
 *  \}
 */

/*---------------------------------------------------------
			硬件接口函数
 ---------------------------------------------------------*/
/**\addtogroup 硬件接口函数
 *  \{
 */
card_err_t card_hw_addgpio(card_obj_t *obj, Uint8_t gpio, Uint8_t dir);
card_err_t card_hw_delgpio(card_obj_t *obj, Uint8_t gpio);
card_err_t card_hw_listgpio(card_obj_t * obj, Uint8_t *list, Uint32_t *list_len);
card_err_t card_hw_setgpio(card_obj_t *obj, Uint8_t gpio, Uint8_t val);
card_err_t card_hw_getgpio(card_obj_t * obj, Uint8_t gpio, Uint8_t *val);
/**
 *  \}
 */
#ifdef __cplusplus
}
#endif

#endif

