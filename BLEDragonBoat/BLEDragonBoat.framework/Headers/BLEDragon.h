//
//  BLEDragon.h
//  BLESolstice
//
//  Created by A$CE on 2017/10/9.
//  Copyright © 2017年 A$CE. All rights reserved.
//

#define BLE_MAIN_RESTORE_IDENTIFIER @"com.iwown.dragon"
#define BLE_MID_AUTUMN_PLIST @"dragonBoat"  //Config file name in @"dragonBoat.plist";

#import "BLESolstice.h"
#import "BLEQuinox.h"
#import <Foundation/Foundation.h>

/**
 Core class, management search and connection, is also the entrance to the SDK.
 Sample @code{self.BLEDragon = [BLEDragon dragonBoat];
 self.BLEDragon.discoverDelegate = self;
 self.BLEDragon.connectDelegate = self;}@endcode
 */
@interface BLEDragon : NSObject

@property (nonatomic ,weak) id<BleDiscoverDelegate>discoverDelegate;
@property (nonatomic ,weak) id<BleConnectDelegate>connectDelegate;

/**
 Represents the current state of a CBManager. <CBManagerState> <CBCentralManagerState> used for below iOS10.
 @return Return to the state of the central manager, you can determine the status of Bluetooth.
 */
- (NSInteger)readManagerPowerState;

/**
 Scan device. You will get the discovered devices in the callback method of discoverDelegate @see solsticeDidDiscoverDeviceWithMAC:
 @param seconds Enter a number of seconds that you want to stop searching after later
 @param uuids The uuids you want to specify when searching
 @param options Same with options in @method scanForPeripheralsWithServices:options:
 */
- (void)startScanForTimeInternal:(NSTimeInterval)seconds
                 andServiceUuids:(NSArray <NSString *>*)uuids
                      andOptions:(NSDictionary<NSString *, id> *)options;
/**
 @see startScanForTimeInternal:andServiceUuids:andOptions:
 Default options is nil.
 @param seconds The uuids you want to specify when searching
 @param uuids Same with options in @method scanForPeripheralsWithServices:options:
 */
- (void)startScanForTimeInternal:(NSTimeInterval)seconds
                 andServiceUuids:(NSArray <NSString *>*)uuids;
/**
 @see startScanForTimeInternal:andServiceUuids:
 Default seconds is 10, uuids is nil, The SDK will choose the correct uuids for the  <BLEProtocol>.
 */
- (void)startScan;
/**
 Stop scan.
 The SDK calls the @see solsticeStopScan method if you have already implemented it.
 */
- (void)stopScan;

/**
 Connectted only. For scenarios with short-term connections, the SDK does not implement the binding mechanism, so there is no need to reconnect. For example, body fat scale products.*/
- (void)connectDevice:(ZRBlePeripheral *)device;

- (void)cancelConnectBy:(id<BLESolstice>)solstice;

/*Class Method ,use @CODE{[[BLEDragon alloc] init];}*/
+ (instancetype)dragonBoat;

/**
 * If you need a <BLESolstice> object to communicate with device, after searching and connecting to the device with BLEDragon, please using the this method initinal the object, you must had a peripheral device that has been connected.
 
 @param zrPeripheral the Device had connected
 @return Follow the BLESolstice agreement object
 */
- (id<BLESolstice>)solsticeWithConnectedPeripheral:(ZRBlePeripheral *)zrPeripheral;

@end