//
//  NextViewController.m
//  YMCZD0
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "NextViewController.h"
static int p_number;

@interface NextViewController (){
    
}

@end

@implementation NextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeSystem];
    btn.frame = CGRectMake(20.0, 160.0, self.view.frame.size.width - 40.0, 50.0);
    [btn addTarget:self action:@selector(btnClicked:) forControlEvents:UIControlEventTouchDown];
    [btn setTitle:@"ADD 1" forState:UIControlStateNormal];
    [self.view addSubview:btn];

    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void) btnClicked:(id) sender {
    ++p_number;
    if ([self.delegate respondsToSelector:@selector(incrementBy1:)]) {
        if (p_number%3 ==0) {
            [self.delegate incrementBy1:p_number];
            [self dismissViewControllerAnimated:YES completion:nil];
        }
    }
}

@end
