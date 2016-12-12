//
//  CZUsedLibraries.h
//  FMDB
//
//  Created by xxb on 2016/11/23.
//  Copyright © 2016年 chenzhou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ifaddrs.h>
#import <arpa/inet.h>

@interface CZUsedLibraries : NSObject

/**
 获取磁盘总空间大小

 @return float MB
 */
+ (CGFloat)diskOfAllSizeMBytes;

/**
 获取磁盘可用空间的大小

 @return float MB
 */
+ (CGFloat)diskOfFreeSizeMBytes;

/**
 获取指定路径下某个文件的大小

 @param filePath 文件名字
 @return 文件大小
 */
+ (long long)fileSizeAtPath:(NSString *)filePath;

/**
 获取文件夹下所有文件的大小

 @param folder 文件夹目录
 @return 文件夹的大小
 */
+ (long long)folderSizeAtPath:(NSString *)folder;

/**
 获取字符（或汉子）的首字母

 @param string 字符串
 @return 首字母
 */
+ (NSString *)firstCharacterWhitString:(NSString *)string;

/**
 将字符串数组按照元素首字母顺序进行排序

 @param array 字符串数组
 @return 首字母键值对
 */
+ (NSDictionary *)dictionaryOrderByCharacterWithOriginalArray:(NSArray *)array;

/**
 获取当前时间
 format: @"yyyy-MM-dd HH:mm:ss"、@"yyyy年MM月dd日 HH时mm分ss秒"
 @param format 返回的时间格式
 @return 返回的时间
 */
+ (NSString *)currentDateWithFormat:(NSString *)format;

/**
 计算上次日期距离现在多久？ 如xx 小时前、xx 分钟前等

 @param lastTime 上次日期（需要和格式相对应）
 @param foamat1 上次日期格式
 @param currentTime 最近日期（需要和格式相对应）
 @param format2 最近日期格式
 @return xx 分钟前、xx 小时前、xx 天前
 */
+ (NSString *)timeIntervalFromLastTime:(NSString *)lastTime
                        lastTimeFormat:(NSString *)foamat1
                         toCurrentTime:(NSString *)currentTime
                     currentTimeFormat:(NSString *)format2;

/**
 计算上次日期距离现在多久？ 如xx 小时前、xx 分钟前等

 @param lastTime 上次日期
 @param currentTime 当前日期
 @return xx 分钟前、xx 小时前、xx 天前
 */
+ (NSString *)timeIntervalFromLastTime:(NSDate *)lastTime
                         ToCurrentTime:(NSDate *)currentTime;


/**
 判断手机号码格式是否正确

 @param mobile 手机号字符串
 @return YES 为正确手机号
 */
+ (BOOL)valiMobile:(NSString *)mobile;

/**
 判断邮箱的格式是否正确

 @param email 邮箱字符串
 @return YES 为正确邮箱
 */
+ (BOOL)isAvailableEmail:(NSString *)email;

/**
 将十六进制颜色转换成 UIColor 对象

 @param string 十六进制字符串
 @return UIColro 对象
 */
+ (UIColor *)colorWithHexString:(NSString *)string;

/**
 对图片进行滤镜处理
 // 怀旧 --> CIPhotoEffectInstant                         单色 --> CIPhotoEffectMono
 // 黑白 --> CIPhotoEffectNoir                            褪色 --> CIPhotoEffectFade
 // 色调 --> CIPhotoEffectTonal                           冲印 --> CIPhotoEffectProcess
 // 岁月 --> CIPhotoEffectTransfer                        铬黄 --> CIPhotoEffectChrome
 // CILinearToSRGBToneCurve, CISRGBToneCurveToLinear, CIGaussianBlur, CIBoxBlur, CIDiscBlur, CISepiaTone, CIDepthOfField
 @param image image
 @param name name
 @return image
 */
+ (UIImage *)filterWithOriginalImage:(UIImage *)image
                          filterName:(NSString *)name;

/**
 对图片进行模糊处理
 // CIGaussianBlur ---> 高斯模糊
 // CIBoxBlur      ---> 均值模糊(Available in iOS 9.0 and later)
 // CIDiscBlur     ---> 环形卷积模糊(Available in iOS 9.0 and later)
 // CIMedianFilter ---> 中值模糊, 用于消除图像噪点, 无需设置radius(Available in iOS 9.0 and later)
 // CIMotionBlur   ---> 运动模糊, 用于模拟相机移动拍摄时的扫尾效果(Available in iOS 9.0 and later)
 @param image image
 @param name name
 @param radius radius
 @return image
 */
+ (UIImage *)blurWithOriginalImage:(UIImage *)image
                          blueName:(NSString *)name
                            radius:(NSInteger)radius;

/**
 调整图片的饱和度、亮度、对比度

 @param image 目标图片
 @param saturation 饱和度
 @param brightness 亮度
 @param contrast 对比图
 @return 图片
 */
+ (UIImage *)colorControlsWithOriginalImage:(UIImage *)image
                                 saturation:(CGFloat)saturation
                                 brightness:(CGFloat)brightness
                                   contrast:(CGFloat)contrast;

/**
 创建一个实时模糊效果view（毛玻璃效果）

 @param frame view frame
 @return effctView
 */
+ (UIVisualEffectView *)effectViewWithFrame:(CGRect)frame;

/**
 全屏截图

 @return 图片
 */
+ (UIImage *)shotScreen;

/**
 截取view中的某个区域生成一张图片

 @param view view
 @param scope <#scope description#>
 @return 图片
 */
+ (UIImage *)shotWithView:(UIView *)view
                    scope:(CGRect)scope;

/**
 压缩图片到指定尺寸大小

 @param image 图片
 @param size size
 @return 图片
 */
+ (UIImage *)compressOriginalImage:(UIImage *)image
                            toSize:(CGSize)size;

/**
 压缩图片到指定文件大小

 @param image 图片
 @param size size
 @return data
 */
+ (NSData *)compressOriginalImage:(UIImage *)image
              toMaxDataSizeKBytes:(CGFloat)size;

/**
 获取IP地址
 #import <ifaddrs.h>
 #import <arpa/inet.h>
 @return IP 地址
 */
+ (NSString *)getIPAddress;

/**
 判断字符串中是否含有空格

 @return YES 有
 */
+ (BOOL)isHaveSpaceString:(NSString *)string;

/**
 判断字符串中是否含有字符串

 @param string1 原始字符串
 @param string2 包含字符串
 @return YES 有
 */
+ (BOOL)isHaveString:(NSString *)string1
            inString:(NSString *)string2;

/**
 判断字符串中是否含有中文

 @param string 原始字符串
 @return YES 有
 */
+ (BOOL)isHaveChinessInString:(NSString *)string;

/**
 判断字符串是否问纯数字

 @param string 原始执法车
 @return YES 是
 */
+ (BOOL)isAllNum:(NSString *)string;

/**
 绘制虚线

 @param lineFrame 虚线frame
 @param length 虚线中短线的宽度
 @param spacing 虚线中短线的距离
 @param color 虚线的颜色
 @return view
 */
+ (UIView *)createDashedLineWithFrame:(CGRect)lineFrame
                           lineLength:(int)length
                          lineSpacing:(int)spacing
                            lineColor:(UIColor *)color;


/**
 找到指定view的根view

 @param view view
 @return 根view
 */
+ (NSArray *)superViews:(UIView *)view;

/**
 两个view 找到公共的节点

 @param viewA view1
 @param ViewB view2
 @return 节点view
 */
+ (UIView *)commonView_1:(UIView *)viewA andView:(UIView *)ViewB;

@end
