//
//  FirstViewController.m
//  DemoUICollectionView
//
//  Created by 徐涛 on 27/08/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import "FirstViewController.h"
#import "CollectionViewCell.h"

NSString *const kCellID = @"collectionCell";

@interface FirstViewController ()

@end

@implementation FirstViewController

#pragma mark -- UICollectionViewDataSource

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
  return 32;
}
- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
  CollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:kCellID forIndexPath:indexPath];
  cell.image.image = [UIImage imageNamed:[NSString stringWithFormat:@"%ld",(long)indexPath.row]];
  return cell;
}

#pragma mark -- UICollectionViewDelegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
  
}
@end
