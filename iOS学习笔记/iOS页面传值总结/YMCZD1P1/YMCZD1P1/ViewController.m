//
//  ViewController.m
//  YMCZD1P1
//
//  Created by tennyxu on 19/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"
#import "NextViewController.h"

@interface ViewController () <NextViewControllerDelegate>

@property (weak, nonatomic) IBOutlet UILabel *dis;

- (IBAction)nextViewController:(id)sender;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _dis.text = @"0";
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender{
    if ([segue.identifier isEqualToString:@"showNextViewController"]) {
        //这里一定不能用alloc重新创建一个NextViewController, 一定是通过这种方式,指向目的的VC
        NextViewController *nextVC = [segue destinationViewController];
        nextVC.delegate = self;
    }
}

- (IBAction)nextViewController:(id)sender {
}

#pragma mark -- NextViewControllerDelegate

- (void)increment:(id)sender withPara:(NSInteger)para {
    _dis.text = [NSString stringWithFormat:@"%ld",(long)para];
}
@end
