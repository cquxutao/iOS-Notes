//
//  NextViewController.m
//  YMCZD1P1
//
//  Created by tennyxu on 19/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "NextViewController.h"

static int number;

@interface NextViewController () {
    struct {
        unsigned int increment:1;
    } _delegateFlag;
}
- (IBAction)add:(id)sender;
- (IBAction)back:(id)sender;

@end

@implementation NextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
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

#pragma mark -- getter/setter
- (void)setDelegate:(id<NextViewControllerDelegate>)delegate {
    _delegate = delegate;
    _delegateFlag.increment = [_delegate respondsToSelector:@selector(increment:withPara:)];
}

- (IBAction)add:(id)sender {
    ++number;
    if (_delegateFlag.increment) {
        //传入了self, 所以代理类会持有这个类(self);
        //为了避免循环引用, 所以这个类不能持有代理类, 所以delegate属性申明为weak;
        [_delegate increment:self withPara:number];
    }
}

- (IBAction)back:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
    
}
@end
