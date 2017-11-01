//
//  NextViewController.m
//  YMCZD1
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "NextViewController.h"
#import "ViewController.h"
static int p_number;

@interface NextViewController ()

@end

@implementation NextViewController{

}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
//    UIStoryboard *mainStoryBoard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
//    ViewController *homeView = [mainStoryBoard instantiateViewControllerWithIdentifier:@"viewController"];
//    self.delegate = homeView;

    
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



- (IBAction)btn:(id)sender {
    ++p_number;
    if ([self.delegate respondsToSelector:@selector(incrementBy1:)]) {
        NSLog(@"代理类实现了incrementBy1:方法");
        if (p_number%3 == 0) {
            [self.delegate incrementBy1:p_number];
            [self dismissViewControllerAnimated:YES completion:^{
                ;
            }];
        }
    } else {
        NSLog(@"代理类没有实现incrementBy1:方法");
    }
    

}
@end
