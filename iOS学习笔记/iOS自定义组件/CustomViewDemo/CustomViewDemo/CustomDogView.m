//
//  CustomDogView.m
//  CustomViewDemo
//
//  Created by 徐涛 on 07/08/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import "CustomDogView.h"
#import "CustomDogViewModel.h"

@interface CustomDogView ()

@property (nonatomic,copy) UIImageView *pic;
@property (nonatomic,copy) UILabel *name;

@end

@implementation CustomDogView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        _pic = [[UIImageView alloc] init];
        [self addSubview:_pic];
        _name = [[UILabel alloc] init];
        [_name setTextAlignment:NSTextAlignmentCenter];
        [_name setFont:[UIFont systemFontOfSize:10.0]];
        [self addSubview:_name];
    }
    return self;
}
- (void)layoutSubviews {
    [super layoutSubviews];
    [_pic setFrame:CGRectMake(0.0, 0.0, self.frame.size.width, self.frame.size.height*0.9)];
    [_name setFrame:CGRectMake(0.0, self.frame.size.height*0.9, self.frame.size.width, self.frame.size.height*0.1)];
}
- (void)setModel:(CustomDogViewModel *)model {
    _model = model;
    _pic.image = [UIImage imageNamed:_model.pic];
    _name.text = _model.name;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end



















