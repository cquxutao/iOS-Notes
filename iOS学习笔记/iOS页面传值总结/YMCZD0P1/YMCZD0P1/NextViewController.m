//
//  NextViewController.m
//  YMCZD0P1
//
//  Created by tennyxu on 19/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "NextViewController.h"
static int number;

@interface NextViewController () {
    struct {
        unsigned int increment: 1;
    } _delegateFlag;
    
    UIButton *backAndAdd;
}

@end

@implementation NextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    backAndAdd = [UIButton buttonWithType:UIButtonTypeSystem];
    [backAndAdd setFrame:CGRectMake(20.0, self.view.center.y - 15.0, self.view.frame.size.width - 40.0, 30.0)];
    [backAndAdd addTarget:self action:@selector(backAndAdd:) forControlEvents:UIControlEventTouchDown];
    [backAndAdd setTitle:@"Back & Add" forState:UIControlStateNormal];
    [self.view addSubview:backAndAdd];
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
#pragma mark -- setter/getter
- (void) setDelegate:(id<NextViewControllerDelegate>)delegate {
    _delegate = delegate;
    _delegateFlag.increment = [_delegate respondsToSelector:@selector(increment:withPara:)];
}

#pragma mark -- selector
- (void)backAndAdd:(id)sender {
    ++number;
    if (number%3 == 0) {
        if (_delegateFlag.increment) {
            [_delegate increment:self withPara:number];
        }
        [self dismissViewControllerAnimated:YES completion:nil];
    }
}
@end
