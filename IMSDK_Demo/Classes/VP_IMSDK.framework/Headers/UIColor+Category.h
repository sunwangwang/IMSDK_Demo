//
//  UIColor+Category.h
//  Common
//
//  Created by zengtao on 15/5/16.
//  Copyright (c) 2015年 miantanteam. All rights reserved.
//

#import <UIKit/UIKit.h>

#define RGBColorHex(color) [UIColor colorWithHexString:color]
#define RGBAColorHex(color, floatAlpha) [UIColor colorWithHexString:color alpha:floatAlpha]
#define RGBColor(r, g, b) [UIColor colorWithRed:(r / 255.0) green:(g / 255.0) blue:(b / 255.0) alpha:1]
#define RGBAColor(r, g, b, a) [UIColor colorWithRed:(r / 255.0) green:(g / 255.0) blue:(b / 255.0) alpha:a]

//颜色转换
#define mRGBColor(r, g, b)         [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define mRGBAColor(r, g, b, a)     [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]



#define GWGOViewControllerBgColor @"000000"
#define DefaultStatusBarColor RGBAColorHex(@"000000", 0.7f)

@interface UIColor (Category)

/*
 * Creating
 */
+ (UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;
+ (UIColor *)colorWithHexString:(NSString *)hexString;
+ (UIColor *)randomColor;

/*
 * Components
 */
- (CGFloat)red;
- (CGFloat)green;
- (CGFloat)blue;
- (CGFloat)alpha;
- (NSString *)hexString;

- (UIColor *)alpha:(CGFloat)alpha;


@end
