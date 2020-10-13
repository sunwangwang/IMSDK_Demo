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
#import "JPUSHService.h"
@interface VPViewController ()

@property (nonatomic, strong) UITextField *field;
@property (nonatomic, strong) UITextField *channelKeyField;
@property (nonatomic, strong) UITextField *subIdField;
@property (nonatomic, strong)  UITextField *netField;

@end

@implementation VPViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
     UIButton *btn = [UIButton new];
       btn.frame = (CGRect) { VPK_SCREEN_WIDTH / 2 - 50, VPK_SCREEN_HEIGHT / 2 - 50, 100, 50 };
       btn.backgroundColor = [UIColor grayColor];
       [btn setTitle:@"去聊天" forState:UIControlStateNormal];
       [btn addTarget:self action:@selector(toChat:) forControlEvents:UIControlEventTouchUpInside];
       [self.view addSubview:btn];

       // 第三方id
       self.field = [[UITextField alloc] initWithFrame:CGRectMake(50, CGRectGetMinY(btn.frame) - 50, VPK_SCREEN_WIDTH - 100, 30)];
       self.field.autocorrectionType = UITextAutocorrectionTypeNo;
       self.field.placeholder = @"请输入三方Id";
       self.field.borderStyle = UITextBorderStyleRoundedRect;
       [self.view addSubview:self.field];

       // channelKeyField
       self.channelKeyField = [[UITextField alloc] initWithFrame:CGRectMake(50, CGRectGetMinY(self.field.frame) - 50, VPK_SCREEN_WIDTH - 100, 30)];
       self.channelKeyField.autocorrectionType = UITextAutocorrectionTypeNo;
       self.channelKeyField.placeholder = @"请输入channelKey";
       self.channelKeyField.borderStyle = UITextBorderStyleRoundedRect;
       [self.view addSubview:self.channelKeyField];

       // channelKeyField
       self.subIdField = [[UITextField alloc] initWithFrame:CGRectMake(50, CGRectGetMinY(self.channelKeyField.frame) - 50, VPK_SCREEN_WIDTH - 100, 30)];
       self.subIdField.autocorrectionType = UITextAutocorrectionTypeNo;
       self.subIdField.placeholder = @"请输入subId";
       self.subIdField.borderStyle = UITextBorderStyleRoundedRect;
       [self.view addSubview:self.subIdField];

}
- (void)toChat:(UIButton *)sender {
    
    NSString *thirdId = self.field.text.length > 0 ? self.field.text : @"";
    //e2ca253babdfd41e3babbe59006d92f0
//    6ba1ece0966a6d2348c033ed775168eb
    NSString *channeKey = self.channelKeyField.text.length > 0 ? self.channelKeyField.text : @"f2e546ffd3f25dd3c06f0279595e1c4d";
    
    NSString *subId =    self.subIdField.text.length > 0 ? self.subIdField.text : @"0";

    NSString *avatar = @"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1597124511771&di=abb6618659423599cb875a22dd9019b9&imgtype=0&src=http%3A%2F%2Fb-ssl.duitang.com%2Fuploads%2Fitem%2F201710%2F22%2F20171022105108_Wm3Bc.jpeg";

    NSString *fromId = thirdId ;
    
    if(fromId.length){
        //设置别名，用于极光推送
           [JPUSHService setAlias:fromId  completion:^(NSInteger iResCode, NSString *iAlias, NSInteger seq) {

           } seq:0] ;
    }
   
    // 备注：fromId 传nil 或者 @"" 表示APP不接收来自客服sdk的推送消息
    
    [[ZTIM sharedIM]loginWithUsername:@"旺旺" avatar:avatar thirdId:thirdId fromId:fromId  otherUserData:@"123" subId:subId channeKey:channeKey  completion:^(BOOL finish) {
        if (finish) {
            VPMsgTableViewController *vc = [VPMsgTableViewController new];
         
            /*
             scanPaths 为数组类型，作用为发送浏览轨迹给坐席 ，可以不传
             
             i1:浏览时间 时间戳s
             i2:浏览的标题（summary）
             i3:浏览的url
             
             */
            vc.scanPaths = @[
                @{
                    @"i1":@"12345678910",
                    @"i2":@"在线客服",
                    @"i3":@"https://xxxxx/xxx"
                }
            ] ;
            
            [self.navigationController pushViewController:vc animated:NO];
        }
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
