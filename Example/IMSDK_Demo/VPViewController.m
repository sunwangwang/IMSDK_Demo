//
//  VPViewController.m
//  IMSDK_Demo
//
//  Created by sunwangwang on 10/09/2020.
//  Copyright (c) 2020 sunwangwang. All rights reserved.
//

#import "VPViewController.h"
//#import <VP_IMSDK/VP_IMSDK.h>
#import <VP_IMSDK/VP_IMSDK.h>
@interface VPViewController ()

@end

@implementation VPViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor yellowColor];
    NSBundle *mainBundle =    [NSBundle bundleForClass:[self class]];
        NSBundle *resourceBundle = [NSBundle bundleWithPath:[mainBundle pathForResource:@"IMSDK_Demo" ofType:@"bundle"]] ;
         NSBundle *imgBundle = [NSBundle bundleWithPath:[resourceBundle pathForResource:@"IMSDK" ofType:@"bundle"]] ;
        
         UIImageView *iv = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 200, 200)];
         [self.view addSubview:iv];
         iv.backgroundColor = [UIColor yellowColor];
    //    UIImage *image = [UIImage imageNamed:@"icon_back_normal" inBundle:[NSBundle bundleForClass:[self class]] compatibleWithTraitCollection:nil];

         
        iv.image =    [UIImage imageNamed:@"icon_back_normal" inBundle:imgBundle compatibleWithTraitCollection:nil];
    
    UIImageView *iv1 = [[UIImageView alloc]initWithFrame:CGRectMake(0, 200, 200, 200)];
       iv1.backgroundColor = [UIColor yellowColor];
       iv1.image =  Image(@"icon_back_normal") ;
       [self.view addSubview:iv1] ;
       
       
       UIImageView *iv2 = [[UIImageView alloc]initWithFrame:CGRectMake(0, 400, 200, 200)];
          iv2.backgroundColor = [UIColor greenColor];
       iv2.image =  [UIImage imageNamed:@"IMSDK_Demo.bundle/IMSDK.bundle/icon_back_normal"] ;
          [self.view addSubview:iv2] ;
	// Do any additional setup after loading the view, typically from a nib.
}
-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [self presentViewController:[VPMsgTableViewController new] animated:YES completion:^{
            
       }];
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
