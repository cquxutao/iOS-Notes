//
//  FirstViewController.m
//  DemoKVO
//
//  Created by tennyxu on 04/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "FirstViewController.h"
#import "TTKVO.h"

@interface FirstViewController ()

@property (strong, nonatomic) TTKVO *ttKVO;
@property (strong, nonatomic) IBOutlet UILabel *dis;
- (IBAction)btn:(id)sender;

@end

@implementation FirstViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  self.ttKVO = [[TTKVO alloc] init];
  // Do any additional setup after loading the view, typically from a nib.
  [self.ttKVO addObserver:self forKeyPath:@"num" options:NSKeyValueObservingOptionNew|NSKeyValueObservingOptionOld context:nil];
  
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
  [self removeObserver:self forKeyPath:@"num"];
}

- (void)dealloc {
  [self removeObserver:self forKeyPath:@"num"];
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
  if (object == self.ttKVO && [keyPath isEqualToString:@"num"]) {
    self.dis.text = [NSString stringWithFormat:@"%@",[change valueForKey:@"new"]];
  }
  NSLog(@"new=%@,old=%@",[change valueForKey:@"new"],[change valueForKey:@"old"]);
}

- (IBAction)btn:(id)sender {
  self.ttKVO.num += 1;
}

@end
