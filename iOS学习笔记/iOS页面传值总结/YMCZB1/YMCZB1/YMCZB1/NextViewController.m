//
//  NextViewController.m
//  YMCZB1
//
//  Created by tennyxu on 05/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "NextViewController.h"
#import "ViewController.h"

@interface NextViewController (){
    int p_number;
}

@end

@implementation NextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    p_number = 0;
    //
//    UIStoryboard *mainStory = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
//    ViewController *vC = [mainStory instantiateViewControllerWithIdentifier:@"viewController"];
//    self.block = ^(int number) {
//        vC.dis.text = [NSString stringWithFormat:@"%d",number];
//    };

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
    self.block(p_number);
    
}
@end
