//
//  SViewController.m
//  DemoNotification
//
//  Created by tennyxu on 04/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "SViewController.h"

@interface SViewController ()
- (IBAction)back:(id)sender;
@property (strong, nonatomic) IBOutlet UITextField *xxx;

@end

@implementation SViewController

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

- (IBAction)back:(id)sender {
  [self dismissViewControllerAnimated:YES completion:^{
    NSString *temp = self.xxx.text;
    NSDictionary *dic = [NSDictionary dictionaryWithObject:temp forKey:@"Y"];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"TestX" object:nil userInfo:dic];
    
  }];
  //
  
  
  
}
@end
