#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class SIPCSDKAuthLevel, SIPCSDKBarcode, SIPCSDKBarcodeBounds, SIPCSDKBarcodeScanMode, SIPCSDKBatteryTelemetry, SIPCSDKBoundsPoint, SIPCSDKCenteringMode, SIPCSDKCenteringModeCompanion, SIPCSDKCenteringWindowLimits, SIPCSDKConnectionState, SIPCSDKDecodeOptions, SIPCSDKDeviceDetails, SIPCSDKEngineId, SIPCSDKEngineType, SIPCSDKEngineTypeCompanion, SIPCSDKExposureMode, SIPCSDKExposureModeCompanion, SIPCSDKExposureParameter, SIPCSDKFlagEditor, SIPCSDKHsmRevision, SIPCSDKImageFormat, SIPCSDKImageRegion, SIPCSDKImageRegionCompanion, SIPCSDKImagerProperties, SIPCSDKKotlinArray<T>, SIPCSDKKotlinByteArray, SIPCSDKKotlinByteIterator, SIPCSDKKotlinEnum<E>, SIPCSDKKotlinEnumCompanion, SIPCSDKKotlinException, SIPCSDKKotlinIllegalStateException, SIPCSDKKotlinPair<__covariant A, __covariant B>, SIPCSDKKotlinRuntimeException, SIPCSDKKotlinThrowable, SIPCSDKLastImageInfo, SIPCSDKLengthLimits, SIPCSDKLightbarColor, SIPCSDKLightsMode, SIPCSDKLightsModeCompanion, SIPCSDKOcrMode, SIPCSDKOcrSettings, SIPCSDKOcrTemplate, SIPCSDKOcrUserTemplate, SIPCSDKRedundancy, SIPCSDKScannerImage, SIPCSDKScannerSymbology, SIPCSDKScannerSymbologyCompanion, SIPCSDKScanningMode, SIPCSDKShowDecodeWindow, SIPCSDKShowDecodeWindowCompanion, SIPCSDKSnapHaloEvent, SIPCSDKSnapHaloEventOnBarcodeScanned, SIPCSDKSnapHaloEventOnBatteryTelemetryChanged, SIPCSDKSnapHaloEventOnConnectionStatus, SIPCSDKSnapHaloEventOnFirmwareVersionChanged, SIPCSDKSnapHaloEventOnSecurityWarning, SIPCSDKSnapHaloEventOnTriggerChanged, SIPCSDKSymbologyConfig, SIPCSDKSymbologyFlag;

@protocol SIPCSDKIBarcodeReader, SIPCSDKIBattery, SIPCSDKIDevice, SIPCSDKIDiagnostics, SIPCSDKIImages, SIPCSDKIImaging, SIPCSDKILight, SIPCSDKIOcr, SIPCSDKISymbology, SIPCSDKKotlinAutoCloseable, SIPCSDKKotlinComparable, SIPCSDKKotlinIterator, SIPCSDKKotlinx_coroutines_coreFlow, SIPCSDKKotlinx_coroutines_coreFlowCollector, SIPCSDKKotlinx_coroutines_coreSharedFlow;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface SIPCSDKBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface SIPCSDKBase (SIPCSDKBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface SIPCSDKMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface SIPCSDKMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorSIPCSDKKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface SIPCSDKNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface SIPCSDKByte : SIPCSDKNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface SIPCSDKUByte : SIPCSDKNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface SIPCSDKShort : SIPCSDKNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface SIPCSDKUShort : SIPCSDKNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface SIPCSDKInt : SIPCSDKNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface SIPCSDKUInt : SIPCSDKNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface SIPCSDKLong : SIPCSDKNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface SIPCSDKULong : SIPCSDKNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface SIPCSDKFloat : SIPCSDKNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface SIPCSDKDouble : SIPCSDKNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface SIPCSDKBoolean : SIPCSDKNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end


/**
 * Connection and general device controls for one SnapHalo scanner.
 * Queries use a fixed three-second timeout, including time waiting for other commands.
 */
__attribute__((swift_name("IDevice")))
@protocol SIPCSDKIDevice
@required

/** Requests 0..255 beeps.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)beepBuzzerTimes:(int32_t)times completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("beepBuzzer(times:completionHandler:)")));

/** Clears the scanner's BLE bond keys; the scanner restarts advertising.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)clearBleBondingWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("clearBleBonding(completionHandler:)")));

/** Reads the device's current details and settings.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)detailsWithCompletionHandler:(void (^)(SIPCSDKDeviceDetails * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("details(completionHandler:)")));

/** Disconnects without disposing the client. Cancel pending Android NFC connections first.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)disconnectWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("disconnect(completionHandler:)")));

/** Returns the current connection state without issuing a command. */
- (SIPCSDKConnectionState *)getConnectionState __attribute__((swift_name("getConnectionState()")));

/** Requests device firmware; throws on timeout, disconnection or invalid response.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getFirmwareWithCompletionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getFirmware(completionHandler:)")));

/** Requests the device model.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getModelWithCompletionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getModel(completionHandler:)")));

/** Plays a firmware melody number in 0..255.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)playBuzzerTonesMelodyNumber:(int32_t)melodyNumber completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("playBuzzerTones(melodyNumber:completionHandler:)")));

/** Powers off the scanner. The BLE connection will end after the command is delivered.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)powerOffWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("powerOff(completionHandler:)")));

/** Reads the connected BLE link's signal strength in dBm; throws if unavailable or disconnected.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readRssiWithCompletionHandler:(void (^)(SIPCSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readRssi(completionHandler:)")));

/** Enables or disables BLE channel sounding. Read the reported value with [details].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setChannelSoundingEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setChannelSounding(enabled:completionHandler:)")));

/** Sets idle timeout in minutes (1..255); completes on BLE write.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setIdleTimeoutTimeoutMinutes:(int32_t)timeoutMinutes completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setIdleTimeout(timeoutMinutes:completionHandler:)")));

/** Sets power-off timeout in seconds; zero selects firmware default.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setPowerOffTimeoutTimeoutSeconds:(int32_t)timeoutSeconds completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setPowerOffTimeout(timeoutSeconds:completionHandler:)")));

/** Successful on-demand RSSI readings in dBm, with no replay or automatic polling. */
@property (readonly) id<SIPCSDKKotlinx_coroutines_coreSharedFlow> rssi __attribute__((swift_name("rssi")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.0")
*/
__attribute__((swift_name("KotlinAutoCloseable")))
@protocol SIPCSDKKotlinAutoCloseable
@required
- (void)close __attribute__((swift_name("close()")));
@end


/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SnapHalo")))
@interface SIPCSDKSnapHalo : SIPCSDKBase <SIPCSDKIDevice, SIPCSDKKotlinAutoCloseable>

/**
 * Creates a Snap device client
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Creates a Snap device client
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)beepBuzzerTimes:(int32_t)times completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("beepBuzzer(times:completionHandler:)")));

/**
 * Cancels owned NFC reading and pending connection work without disconnecting the scanner.
 */
- (void)cancelPendingConnection __attribute__((swift_name("cancelPendingConnection()")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)clearBleBondingWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("clearBleBonding(completionHandler:)")));

/** Equivalent to [dispose]. */
- (void)close __attribute__((swift_name("close()")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)detailsWithCompletionHandler:(void (^)(SIPCSDKDeviceDetails * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("details(completionHandler:)")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)disconnectWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("disconnect(completionHandler:)")));

/** Releases the owned scanner once. A disposed client cannot be reused. */
- (void)dispose __attribute__((swift_name("dispose()")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 */
- (SIPCSDKConnectionState *)getConnectionState __attribute__((swift_name("getConnectionState()")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getFirmwareWithCompletionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getFirmware(completionHandler:)")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getModelWithCompletionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getModel(completionHandler:)")));

/**
 * Observes [events] through main-thread callbacks without exposing a subscription class.
 */
- (id<SIPCSDKKotlinAutoCloseable>)observeEventsOnEvent:(void (^)(SIPCSDKSnapHaloEvent *))onEvent __attribute__((swift_name("observeEvents(onEvent:)")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)playBuzzerTonesMelodyNumber:(int32_t)melodyNumber completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("playBuzzerTones(melodyNumber:completionHandler:)")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)powerOffWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("powerOff(completionHandler:)")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readRssiWithCompletionHandler:(void (^)(SIPCSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readRssi(completionHandler:)")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setChannelSoundingEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setChannelSounding(enabled:completionHandler:)")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setIdleTimeoutTimeoutMinutes:(int32_t)timeoutMinutes completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setIdleTimeout(timeoutMinutes:completionHandler:)")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setPowerOffTimeoutTimeoutSeconds:(int32_t)timeoutSeconds completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setPowerOffTimeout(timeoutSeconds:completionHandler:)")));

/**
 * Presents the iOS NFC sheet and connects after a valid tag read. Call on the main
 * thread from a user action. Reuses an active read. [onError] receives NFC and
 * connection failures on the main thread; dismissing the sheet is not an error.
 * Android apps pair through `SnapHaloAndroid` instead.
 */
- (void)startPairingOnError:(void (^)(NSString *))onError __attribute__((swift_name("startPairing(onError:)")));

/** Current scanner authorization */
@property (readonly) SIPCSDKAuthLevel *authLevel __attribute__((swift_name("authLevel")));

/** Barcode trigger, scan mode, symbology, and decoder diagnostics/settings. */
@property (readonly) id<SIPCSDKIBarcodeReader> barcode __attribute__((swift_name("barcode")));

/** Battery state and a fresh telemetry query. */
@property (readonly) id<SIPCSDKIBattery> battery __attribute__((swift_name("battery")));

/** Platform BLE identifier */
@property (readonly) NSString * _Nullable connectedPeripheralIdentifier __attribute__((swift_name("connectedPeripheralIdentifier")));

/**
 * Broadcast stream with no replay. Start collecting before connecting or scanning.
 */
@property (readonly) id<SIPCSDKKotlinx_coroutines_coreSharedFlow> events __attribute__((swift_name("events")));

/** Verified hardware serial for the current connection, if attestation succeeded. */
@property (readonly) SIPCSDKLong * _Nullable hardwareSerial __attribute__((swift_name("hardwareSerial")));

/** Light-bar controls. */
@property (readonly) id<SIPCSDKILight> light __attribute__((swift_name("light")));

/**
 * SnapHalo entry point with [barcode], [light], and [battery] controls, plus typed [events].
 */
@property (readonly) id<SIPCSDKKotlinx_coroutines_coreSharedFlow> rssi __attribute__((swift_name("rssi")));
@end


/** Typed notifications from a SnapHalo client. Command failures are thrown to the caller. */
__attribute__((swift_name("SnapHaloEvent")))
@interface SIPCSDKSnapHaloEvent : SIPCSDKBase
@end


/**
 * Successfully decoded barcode.
 * @property barcode Barcode text and symbology.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SnapHaloEvent.OnBarcodeScanned")))
@interface SIPCSDKSnapHaloEventOnBarcodeScanned : SIPCSDKSnapHaloEvent
- (instancetype)initWithBarcode:(SIPCSDKBarcode *)barcode __attribute__((swift_name("init(barcode:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKSnapHaloEventOnBarcodeScanned *)doCopyBarcode:(SIPCSDKBarcode *)barcode __attribute__((swift_name("doCopy(barcode:)")));

/**
 * Successfully decoded barcode.
 * @property barcode Barcode text and symbology.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Successfully decoded barcode.
 * @property barcode Barcode text and symbology.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Successfully decoded barcode.
 * @property barcode Barcode text and symbology.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKBarcode *barcode __attribute__((swift_name("barcode")));
@end


/**
 * Updated battery telemetry.
 * @property telemetry Latest device battery reading.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SnapHaloEvent.OnBatteryTelemetryChanged")))
@interface SIPCSDKSnapHaloEventOnBatteryTelemetryChanged : SIPCSDKSnapHaloEvent
- (instancetype)initWithTelemetry:(SIPCSDKBatteryTelemetry *)telemetry __attribute__((swift_name("init(telemetry:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKSnapHaloEventOnBatteryTelemetryChanged *)doCopyTelemetry:(SIPCSDKBatteryTelemetry *)telemetry __attribute__((swift_name("doCopy(telemetry:)")));

/**
 * Updated battery telemetry.
 * @property telemetry Latest device battery reading.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Updated battery telemetry.
 * @property telemetry Latest device battery reading.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Updated battery telemetry.
 * @property telemetry Latest device battery reading.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKBatteryTelemetry *telemetry __attribute__((swift_name("telemetry")));
@end


/**
 * Connection transition with the error captured at notification time.
 * @property connectionState New transport state.
 * @property errorMessage Transport error at this transition, if any.
 * @property authLevel Scanner authorization captured at this transition.
 * @property hardwareSerial Verified scanner serial, when hardware attestation succeeded.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SnapHaloEvent.OnConnectionStatus")))
@interface SIPCSDKSnapHaloEventOnConnectionStatus : SIPCSDKSnapHaloEvent
- (instancetype)initWithConnectionState:(SIPCSDKConnectionState *)connectionState errorMessage:(NSString * _Nullable)errorMessage authLevel:(SIPCSDKAuthLevel *)authLevel hardwareSerial:(SIPCSDKLong * _Nullable)hardwareSerial __attribute__((swift_name("init(connectionState:errorMessage:authLevel:hardwareSerial:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKSnapHaloEventOnConnectionStatus *)doCopyConnectionState:(SIPCSDKConnectionState *)connectionState errorMessage:(NSString * _Nullable)errorMessage authLevel:(SIPCSDKAuthLevel *)authLevel hardwareSerial:(SIPCSDKLong * _Nullable)hardwareSerial __attribute__((swift_name("doCopy(connectionState:errorMessage:authLevel:hardwareSerial:)")));

/**
 * Connection transition with the error captured at notification time.
 * @property connectionState New transport state.
 * @property errorMessage Transport error at this transition, if any.
 * @property authLevel Scanner authorization captured at this transition.
 * @property hardwareSerial Verified scanner serial, when hardware attestation succeeded.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Connection transition with the error captured at notification time.
 * @property connectionState New transport state.
 * @property errorMessage Transport error at this transition, if any.
 * @property authLevel Scanner authorization captured at this transition.
 * @property hardwareSerial Verified scanner serial, when hardware attestation succeeded.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Connection transition with the error captured at notification time.
 * @property connectionState New transport state.
 * @property errorMessage Transport error at this transition, if any.
 * @property authLevel Scanner authorization captured at this transition.
 * @property hardwareSerial Verified scanner serial, when hardware attestation succeeded.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKAuthLevel *authLevel __attribute__((swift_name("authLevel")));
@property (readonly) SIPCSDKConnectionState *connectionState __attribute__((swift_name("connectionState")));
@property (readonly) NSString * _Nullable errorMessage __attribute__((swift_name("errorMessage")));
@property (readonly) SIPCSDKLong * _Nullable hardwareSerial __attribute__((swift_name("hardwareSerial")));
@end


/**
 * Updated device firmware version.
 * @property version Device major.minor firmware version.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SnapHaloEvent.OnFirmwareVersionChanged")))
@interface SIPCSDKSnapHaloEventOnFirmwareVersionChanged : SIPCSDKSnapHaloEvent
- (instancetype)initWithVersion:(NSString *)version __attribute__((swift_name("init(version:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKSnapHaloEventOnFirmwareVersionChanged *)doCopyVersion:(NSString *)version __attribute__((swift_name("doCopy(version:)")));

/**
 * Updated device firmware version.
 * @property version Device major.minor firmware version.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Updated device firmware version.
 * @property version Device major.minor firmware version.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Updated device firmware version.
 * @property version Device major.minor firmware version.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *version __attribute__((swift_name("version")));
@end


/** Optional hardware attestation could not be completed. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SnapHaloEvent.OnSecurityWarning")))
@interface SIPCSDKSnapHaloEventOnSecurityWarning : SIPCSDKSnapHaloEvent
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKSnapHaloEventOnSecurityWarning *)doCopyMessage:(NSString *)message __attribute__((swift_name("doCopy(message:)")));

/** Optional hardware attestation could not be completed. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Optional hardware attestation could not be completed. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Optional hardware attestation could not be completed. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end


/**
 * Physical or device-reported trigger transition.
 * @property isPressed Whether the trigger is pressed.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SnapHaloEvent.OnTriggerChanged")))
@interface SIPCSDKSnapHaloEventOnTriggerChanged : SIPCSDKSnapHaloEvent
- (instancetype)initWithIsPressed:(BOOL)isPressed __attribute__((swift_name("init(isPressed:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKSnapHaloEventOnTriggerChanged *)doCopyIsPressed:(BOOL)isPressed __attribute__((swift_name("doCopy(isPressed:)")));

/**
 * Physical or device-reported trigger transition.
 * @property isPressed Whether the trigger is pressed.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Physical or device-reported trigger transition.
 * @property isPressed Whether the trigger is pressed.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Physical or device-reported trigger transition.
 * @property isPressed Whether the trigger is pressed.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isPressed __attribute__((swift_name("isPressed")));
@end


/**
 * Barcode controls. Writes complete on BLE delivery, not firmware acknowledgement; failures throw.
 * Queries use a fixed three-second timeout, including time waiting for other commands.
 */
__attribute__((swift_name("IBarcodeReader")))
@protocol SIPCSDKIBarcodeReader
@required

/** Requests scan-engine firmware; throws on timeout, disconnection or invalid response.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getFirmwareWithCompletionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getFirmware(completionHandler:)")));

/** Reads the current device setting, or null for an unknown firmware mode.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getScanModeWithCompletionHandler:(void (^)(SIPCSDKBarcodeScanMode * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getScanMode(completionHandler:)")));

/**
 * Reads enabled states for all individually supported formats from the scanner.
 * Excludes deprecated formats and control values such as All. Throws on query failure or timeout.
 * Every call requests a fresh device-details snapshot; this does not use cached settings.
 * Queries have a fixed three-second timeout, including time waiting for other commands.
 * @return Map from each supported individual format to its reported enabled state.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSymobologiesWithCompletionHandler:(void (^)(NSDictionary<SIPCSDKScannerSymbology *, SIPCSDKBoolean *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getSymobologies(completionHandler:)")));

/** Enables or disables the beep after a successful scan.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setBeepOnScanEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setBeepOnScan(enabled:completionHandler:)")));

/** Enables or disables the decoder centering window.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCenteringModeEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setCenteringMode(enabled:completionHandler:)")));

/** Sets the continuous-mode scan interval in milliseconds (0..65535). Call after [setScanMode].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setContinuousScanIntervalIntervalMs:(int32_t)intervalMs completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setContinuousScanInterval(intervalMs:completionHandler:)")));

/**
 * Enables or disables all barcode formats through the firmware master toggle.
 * Completes on BLE write. Use [getSymobologies] to read the device's reported states.
 * @param enabled True to enable all formats; false to disable all formats.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setEnableAllSymbologiesEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setEnableAllSymbologies(enabled:completionHandler:)")));

/** Sets OCR polarity and template flags; passport must be used alone.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setOcrModeTemplateMode:(SIPCSDKOcrMode *)mode templateMask:(int32_t)templateMask completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setOcrModeTemplate(mode:templateMask:completionHandler:)")));

/** Powers the scan engine on or off while leaving the BLE link active.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setScanEnginePowerOn:(BOOL)on completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setScanEnginePower(on:completionHandler:)")));

/** Sets scan mode; continuous modes also set the scan interval to 100 ms.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setScanModeMode:(SIPCSDKBarcodeScanMode *)mode completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setScanMode(mode:completionHandler:)")));

/**
 * Enables or disables one format from [ScannerSymbology.Supported].
 * For the master toggle, use [setEnableAllSymbologies]. Completes on BLE write;
 * use [getSymobologies] to read the scanner's reported settings afterward.
 * @param symbology Supported individual format; deprecated and control entries are rejected.
 * @param enabled Whether to enable the format.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setSymbologySymbology:(SIPCSDKScannerSymbology *)symbology enabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setSymbology(symbology:enabled:completionHandler:)")));

/** Enables or disables vibration after a successful scan.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setVibrateOnScanEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setVibrateOnScan(enabled:completionHandler:)")));

/** Presses the scanner trigger. Pair with [stopScan].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)startScanWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("startScan(completionHandler:)")));

/** Releases the scanner trigger.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)stopScanWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("stopScan(completionHandler:)")));

/** Read-only scan-engine identity and diagnostics. */
@property (readonly) id<SIPCSDKIDiagnostics> diagnostics __attribute__((swift_name("diagnostics")));

/** Stored-image retrieval and new image capture from the scan engine. */
@property (readonly) id<SIPCSDKIImages> images __attribute__((swift_name("images")));

/** Current-session scan-engine lighting, exposure, sleep, and decoding controls. */
@property (readonly) id<SIPCSDKIImaging> imaging __attribute__((swift_name("imaging")));

/** Last reported trigger state. */
@property (readonly) BOOL isTriggerPressed __attribute__((swift_name("isTriggerPressed")));

/** OCR mode/template readback and custom user-template controls. */
@property (readonly) id<SIPCSDKIOcr> ocr __attribute__((swift_name("ocr")));

/** Current-session Honeywell HSM flags and accepted lengths for individual formats. */
@property (readonly) id<SIPCSDKISymbology> symbology __attribute__((swift_name("symbology")));
@end


/** Cached battery state and an explicit telemetry query. */
__attribute__((swift_name("IBattery")))
@protocol SIPCSDKIBattery
@required

/** Requests a fresh reading from the scanner.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTelemetryWithCompletionHandler:(void (^)(SIPCSDKBatteryTelemetry * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getTelemetry(completionHandler:)")));

/** Last battery response, or null before a reading or after disconnect. */
@property (readonly) SIPCSDKBatteryTelemetry * _Nullable telemetry __attribute__((swift_name("telemetry")));
@end


/** Read-only identity and diagnostics of the scan engine. The engine must be active. */
__attribute__((swift_name("IDiagnostics")))
@protocol SIPCSDKIDiagnostics
@required

/** Describes one decoder error code.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)describeErrorCode:(int32_t)code completionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("describeError(code:completionHandler:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)engineIdWithCompletionHandler:(void (^)(SIPCSDKEngineId * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("engineId(completionHandler:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)engineTypeWithCompletionHandler:(void (^)(SIPCSDKEngineType * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("engineType(completionHandler:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)imagerPropertiesWithCompletionHandler:(void (^)(SIPCSDKImagerProperties * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("imagerProperties(completionHandler:)")));

/** Returns whether the scan engine answers an HSM engine-type probe.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)isHsmAvailableWithCompletionHandler:(void (^)(SIPCSDKBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("isHsmAvailable(completionHandler:)")));

/** Milliseconds spent on the last decode.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)lastDecodeTimeMsWithCompletionHandler:(void (^)(SIPCSDKLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("lastDecodeTimeMs(completionHandler:)")));

/** Largest decoder message length in characters.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)maxMessageCharsWithCompletionHandler:(void (^)(SIPCSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("maxMessageChars(completionHandler:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)revisionWhich:(SIPCSDKHsmRevision *)which completionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("revision(which:completionHandler:)")));
@end


/** Image metadata and stored-image retrieval from the scan engine. */
__attribute__((swift_name("IImages")))
@protocol SIPCSDKIImages
@required

/** Retrieves the stored image. [onProgress] receives fractions from 0 to 1 during BLE transfer.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)lastImageTimeoutMs:(int64_t)timeoutMs onProgress:(void (^ _Nullable)(SIPCSDKFloat *))onProgress completionHandler:(void (^)(SIPCSDKScannerImage * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("lastImage(timeoutMs:onProgress:completionHandler:)")));

/** Reads the dimensions and byte count of the engine's stored image.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)lastImageInfoWithCompletionHandler:(void (^)(SIPCSDKLastImageInfo * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("lastImageInfo(completionHandler:)")));
@end


/** Current-session scan-engine lighting, exposure, sleep, centering, and decoding controls. */
__attribute__((swift_name("IImaging")))
@protocol SIPCSDKIImaging
@required

/** Reads the extended centering mode.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)centeringModeWithCompletionHandler:(void (^)(SIPCSDKCenteringMode * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("centeringMode(completionHandler:)")));

/** Reads whether the HSM centering window is enabled.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)centeringWindowEnabledWithCompletionHandler:(void (^)(SIPCSDKBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("centeringWindowEnabled(completionHandler:)")));

/** Reads allowed corner ranges for the extended or standard centering window.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)centeringWindowLimitsExtended:(BOOL)extended completionHandler:(void (^)(SIPCSDKCenteringWindowLimits * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("centeringWindowLimits(extended:completionHandler:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)decodeOptionsWithCompletionHandler:(void (^)(SIPCSDKDecodeOptions * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("decodeOptions(completionHandler:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)exposureModeWithCompletionHandler:(void (^)(SIPCSDKExposureMode * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("exposureMode(completionHandler:)")));

/** Raw parameter/value pairs. The decoder may omit parameter IDs; confirm on hardware before interpreting them.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)exposureSettingsRawWithCompletionHandler:(void (^)(NSArray<SIPCSDKKotlinPair<SIPCSDKInt *, SIPCSDKInt *> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("exposureSettingsRaw(completionHandler:)")));

/** Reads the active lighting mode, or the decoder default when [current] is false.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)lightsModeCurrent:(BOOL)current completionHandler:(void (^)(SIPCSDKLightsMode * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("lightsMode(current:completionHandler:)")));

/** Selects the extended centering mode; window modes use the engine's existing rectangle.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCenteringModeMode:(SIPCSDKCenteringMode *)mode completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setCenteringMode(mode:completionHandler:)")));

/** Sets the HSM centering-window switch. This differs from the legacy barcode centering command.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCenteringWindowEnabledEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setCenteringWindowEnabled(enabled:completionHandler:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDecodeOptionsOptions:(SIPCSDKDecodeOptions *)options completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setDecodeOptions(options:completionHandler:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setExposureModeMode:(SIPCSDKExposureMode *)mode completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setExposureMode(mode:completionHandler:)")));

/** Validates all values, then writes up to eight exposure parameters per request.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setExposureSettingsValues:(NSDictionary<SIPCSDKExposureParameter *, SIPCSDKInt *> *)values completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setExposureSettings(values:completionHandler:)")));

/** Sets the active lighting mode, or the decoder default when [current] is false.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setLightsModeMode:(SIPCSDKLightsMode *)mode current:(BOOL)current completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setLightsMode(mode:current:completionHandler:)")));

/** Sets linear decoder priority. StarScanner marks firmware behavior unconfirmed.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setScanningModeMode:(SIPCSDKScanningMode *)mode completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setScanningMode(mode:completionHandler:)")));

/** Sets the decoder's debug-window overlay mode.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setShowDecodeWindowMode:(SIPCSDKShowDecodeWindow *)mode completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setShowDecodeWindow(mode:completionHandler:)")));

/** Sets the scan-engine sleep timeout in milliseconds; must be nonnegative.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setSleepTimeoutMsMs:(int32_t)ms completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setSleepTimeoutMs(ms:completionHandler:)")));

/** Reads the decoder's debug-window overlay mode.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showDecodeWindowWithCompletionHandler:(void (^)(SIPCSDKShowDecodeWindow * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showDecodeWindow(completionHandler:)")));
@end


/** Light-bar, targeting aimer, and decode illumination controls. */
__attribute__((swift_name("ILight")))
@protocol SIPCSDKILight
@required

/** Sets the scanner light bar.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setColorColor:(SIPCSDKLightbarColor *)color completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setColor(color:completionHandler:)")));

/** Enables or disables the targeting aimer.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDecodeAimerEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setDecodeAimer(enabled:completionHandler:)")));

/** Enables or disables decode illumination.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDecodeLightEnabled:(BOOL)enabled completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setDecodeLight(enabled:completionHandler:)")));
@end


/** HSM OCR settings readback and custom user-template controls. */
__attribute__((swift_name("IOcr")))
@protocol SIPCSDKIOcr
@required

/** Writes 1..320 ASCII characters. Enable [com.ipcmobile.snapipcsdk.models.OcrTemplate.User] for use.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setUserTemplateMode:(SIPCSDKOcrMode *)mode template:(NSString *)template_ completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setUserTemplate(mode:template:completionHandler:)")));

/** Reads the engine's current OCR mode and template bitmask.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)settingsWithCompletionHandler:(void (^)(SIPCSDKOcrSettings * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("settings(completionHandler:)")));

/** Reads the current custom OCR template and its video mode.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)userTemplateWithCompletionHandler:(void (^)(SIPCSDKOcrUserTemplate * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("userTemplate(completionHandler:)")));
@end


/** Per-format Honeywell decoder settings. Writes apply to the current scan-engine session. */
__attribute__((swift_name("ISymbology")))
@protocol SIPCSDKISymbology
@required

/** Reads decoder-supported length limits for a range-capable format.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)lengthLimitsSymbology:(SIPCSDKScannerSymbology *)symbology completionHandler:(void (^)(SIPCSDKLengthLimits * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("lengthLimits(symbology:completionHandler:)")));

/** Reads current HSM flags and, where supported, accepted barcode lengths.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readSymbology:(SIPCSDKScannerSymbology *)symbology completionHandler:(void (^)(SIPCSDKSymbologyConfig * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("read(symbology:completionHandler:)")));

/** Reads repeat-read confirmation for one format. Firmware support needs device verification.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)redundancySymbology:(SIPCSDKScannerSymbology *)symbology completionHandler:(void (^)(SIPCSDKRedundancy * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("redundancy(symbology:completionHandler:)")));

/** Restores decoder defaults for one format, [ScannerSymbology.SYM_POSTALS], or [ScannerSymbology.SYM_ALL].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resetToDefaultsSymbology:(SIPCSDKScannerSymbology *)symbology completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("resetToDefaults(symbology:completionHandler:)")));

/** Replaces the entire HSM flags word, including the enable bit. Use [update] for one flag.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setFlagsSymbology:(SIPCSDKScannerSymbology *)symbology flags:(int32_t)flags completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setFlags(symbology:flags:completionHandler:)")));

/** Sets accepted lengths for a range-capable format.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setLengthRangeSymbology:(SIPCSDKScannerSymbology *)symbology min:(int32_t)min max:(int32_t)max completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setLengthRange(symbology:min:max:completionHandler:)")));

/** Sets repeat-read confirmation for one format or [ScannerSymbology.SYM_ALL]. Firmware support needs device verification.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setRedundancySymbology:(SIPCSDKScannerSymbology *)symbology enabled:(BOOL)enabled count:(int32_t)count completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("setRedundancy(symbology:enabled:count:completionHandler:)")));

/** Reads, edits, and writes flags. By default reads back and confirms the applied value.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateSymbology:(SIPCSDKScannerSymbology *)symbology verify:(BOOL)verify edit:(void (^)(SIPCSDKFlagEditor *))edit completionHandler:(void (^)(SIPCSDKSymbologyConfig * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("update(symbology:verify:edit:completionHandler:)")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol SIPCSDKKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface SIPCSDKKotlinEnum<E> : SIPCSDKBase <SIPCSDKKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) SIPCSDKKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end


/** Current scanner authorization, separate from Bluetooth pairing or encryption. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AuthLevel")))
@interface SIPCSDKAuthLevel : SIPCSDKKotlinEnum<SIPCSDKAuthLevel *>
+ (instancetype)alloc __attribute__((unavailable));

/** Current scanner authorization, separate from Bluetooth pairing or encryption. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKAuthLevel *locked __attribute__((swift_name("locked")));
@property (class, readonly) SIPCSDKAuthLevel *tapped __attribute__((swift_name("tapped")));
@property (class, readonly) SIPCSDKAuthLevel *operational __attribute__((swift_name("operational")));
+ (SIPCSDKKotlinArray<SIPCSDKAuthLevel *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKAuthLevel *> *entries __attribute__((swift_name("entries")));
@end


/**
 * Decoded barcode text and symbology.
 * @property value UTF-8 barcode text, trimmed of edge nulls and whitespace.
 * @property symbology Human-readable Honeywell format name, or an Unknown label.
 * @property symbologyCode Unsigned Honeywell code; not a settings symbology ID.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Barcode")))
@interface SIPCSDKBarcode : SIPCSDKBase
- (instancetype)initWithValue:(NSString *)value symbology:(NSString *)symbology symbologyCode:(int32_t)symbologyCode __attribute__((swift_name("init(value:symbology:symbologyCode:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKBarcode *)doCopyValue:(NSString *)value symbology:(NSString *)symbology symbologyCode:(int32_t)symbologyCode __attribute__((swift_name("doCopy(value:symbology:symbologyCode:)")));

/**
 * Decoded barcode text and symbology.
 * @property value UTF-8 barcode text, trimmed of edge nulls and whitespace.
 * @property symbology Human-readable Honeywell format name, or an Unknown label.
 * @property symbologyCode Unsigned Honeywell code; not a settings symbology ID.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Decoded barcode text and symbology.
 * @property value UTF-8 barcode text, trimmed of edge nulls and whitespace.
 * @property symbology Human-readable Honeywell format name, or an Unknown label.
 * @property symbologyCode Unsigned Honeywell code; not a settings symbology ID.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Decoded barcode text and symbology.
 * @property value UTF-8 barcode text, trimmed of edge nulls and whitespace.
 * @property symbology Human-readable Honeywell format name, or an Unknown label.
 * @property symbologyCode Unsigned Honeywell code; not a settings symbology ID.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *symbology __attribute__((swift_name("symbology")));
@property (readonly) int32_t symbologyCode __attribute__((swift_name("symbologyCode")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end


/** Last barcode corners and dimensions in image pixels. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BarcodeBounds")))
@interface SIPCSDKBarcodeBounds : SIPCSDKBase
- (instancetype)initWithTopLeft:(SIPCSDKBoundsPoint *)topLeft topRight:(SIPCSDKBoundsPoint *)topRight bottomLeft:(SIPCSDKBoundsPoint *)bottomLeft bottomRight:(SIPCSDKBoundsPoint *)bottomRight imageWidth:(int32_t)imageWidth imageHeight:(int32_t)imageHeight __attribute__((swift_name("init(topLeft:topRight:bottomLeft:bottomRight:imageWidth:imageHeight:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKBarcodeBounds *)doCopyTopLeft:(SIPCSDKBoundsPoint *)topLeft topRight:(SIPCSDKBoundsPoint *)topRight bottomLeft:(SIPCSDKBoundsPoint *)bottomLeft bottomRight:(SIPCSDKBoundsPoint *)bottomRight imageWidth:(int32_t)imageWidth imageHeight:(int32_t)imageHeight __attribute__((swift_name("doCopy(topLeft:topRight:bottomLeft:bottomRight:imageWidth:imageHeight:)")));

/** Last barcode corners and dimensions in image pixels. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Last barcode corners and dimensions in image pixels. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Last barcode corners and dimensions in image pixels. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKBoundsPoint *bottomLeft __attribute__((swift_name("bottomLeft")));
@property (readonly) SIPCSDKBoundsPoint *bottomRight __attribute__((swift_name("bottomRight")));
@property (readonly) int32_t imageHeight __attribute__((swift_name("imageHeight")));
@property (readonly) int32_t imageWidth __attribute__((swift_name("imageWidth")));
@property (readonly) SIPCSDKBoundsPoint *topLeft __attribute__((swift_name("topLeft")));
@property (readonly) SIPCSDKBoundsPoint *topRight __attribute__((swift_name("topRight")));
@end


/**
 * Barcode scanning modes supported by the device-setting command.
 * @property wireValue Byte value encoded in the set-trigger-mode command.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BarcodeScanMode")))
@interface SIPCSDKBarcodeScanMode : SIPCSDKKotlinEnum<SIPCSDKBarcodeScanMode *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Barcode scanning modes supported by the device-setting command.
 * @property wireValue Byte value encoded in the set-trigger-mode command.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKBarcodeScanMode *single __attribute__((swift_name("single")));
@property (class, readonly) SIPCSDKBarcodeScanMode *continuous __attribute__((swift_name("continuous")));
@property (class, readonly) SIPCSDKBarcodeScanMode *continuousunique __attribute__((swift_name("continuousunique")));
+ (SIPCSDKKotlinArray<SIPCSDKBarcodeScanMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKBarcodeScanMode *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t wireValue __attribute__((swift_name("wireValue")));
@end


/**
 * Battery reading reported by the scanner.
 * @property stateOfCharge Charge percentage clamped to 0..100.
 * @property voltage Battery voltage in volts.
 * @property remainingCapacityMah Remaining capacity in milliamp-hours.
 * @property fullChargeCapacityMah Full-charge capacity in milliamp-hours.
 * @property designCapacityMah Design capacity in milliamp-hours.
 * @property temperatureCelsius Temperature in degrees Celsius, rounded to two decimal places.
 * @property isCharging True when averageCurrentMa is positive.
 * @property averageCurrentMa Signed average current in milliamps.
 * @property cycleCount Reported battery cycle count.
 * @property stateOfHealth Health percentage clamped to 0..100.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BatteryTelemetry")))
@interface SIPCSDKBatteryTelemetry : SIPCSDKBase
- (instancetype)initWithStateOfCharge:(int32_t)stateOfCharge voltage:(double)voltage remainingCapacityMah:(int32_t)remainingCapacityMah fullChargeCapacityMah:(int32_t)fullChargeCapacityMah designCapacityMah:(int32_t)designCapacityMah temperatureCelsius:(double)temperatureCelsius isCharging:(BOOL)isCharging averageCurrentMa:(int32_t)averageCurrentMa cycleCount:(int32_t)cycleCount stateOfHealth:(int32_t)stateOfHealth __attribute__((swift_name("init(stateOfCharge:voltage:remainingCapacityMah:fullChargeCapacityMah:designCapacityMah:temperatureCelsius:isCharging:averageCurrentMa:cycleCount:stateOfHealth:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKBatteryTelemetry *)doCopyStateOfCharge:(int32_t)stateOfCharge voltage:(double)voltage remainingCapacityMah:(int32_t)remainingCapacityMah fullChargeCapacityMah:(int32_t)fullChargeCapacityMah designCapacityMah:(int32_t)designCapacityMah temperatureCelsius:(double)temperatureCelsius isCharging:(BOOL)isCharging averageCurrentMa:(int32_t)averageCurrentMa cycleCount:(int32_t)cycleCount stateOfHealth:(int32_t)stateOfHealth __attribute__((swift_name("doCopy(stateOfCharge:voltage:remainingCapacityMah:fullChargeCapacityMah:designCapacityMah:temperatureCelsius:isCharging:averageCurrentMa:cycleCount:stateOfHealth:)")));

/**
 * Battery reading reported by the scanner.
 * @property stateOfCharge Charge percentage clamped to 0..100.
 * @property voltage Battery voltage in volts.
 * @property remainingCapacityMah Remaining capacity in milliamp-hours.
 * @property fullChargeCapacityMah Full-charge capacity in milliamp-hours.
 * @property designCapacityMah Design capacity in milliamp-hours.
 * @property temperatureCelsius Temperature in degrees Celsius, rounded to two decimal places.
 * @property isCharging True when averageCurrentMa is positive.
 * @property averageCurrentMa Signed average current in milliamps.
 * @property cycleCount Reported battery cycle count.
 * @property stateOfHealth Health percentage clamped to 0..100.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Battery reading reported by the scanner.
 * @property stateOfCharge Charge percentage clamped to 0..100.
 * @property voltage Battery voltage in volts.
 * @property remainingCapacityMah Remaining capacity in milliamp-hours.
 * @property fullChargeCapacityMah Full-charge capacity in milliamp-hours.
 * @property designCapacityMah Design capacity in milliamp-hours.
 * @property temperatureCelsius Temperature in degrees Celsius, rounded to two decimal places.
 * @property isCharging True when averageCurrentMa is positive.
 * @property averageCurrentMa Signed average current in milliamps.
 * @property cycleCount Reported battery cycle count.
 * @property stateOfHealth Health percentage clamped to 0..100.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Battery reading reported by the scanner.
 * @property stateOfCharge Charge percentage clamped to 0..100.
 * @property voltage Battery voltage in volts.
 * @property remainingCapacityMah Remaining capacity in milliamp-hours.
 * @property fullChargeCapacityMah Full-charge capacity in milliamp-hours.
 * @property designCapacityMah Design capacity in milliamp-hours.
 * @property temperatureCelsius Temperature in degrees Celsius, rounded to two decimal places.
 * @property isCharging True when averageCurrentMa is positive.
 * @property averageCurrentMa Signed average current in milliamps.
 * @property cycleCount Reported battery cycle count.
 * @property stateOfHealth Health percentage clamped to 0..100.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t averageCurrentMa __attribute__((swift_name("averageCurrentMa")));
@property (readonly) int32_t cycleCount __attribute__((swift_name("cycleCount")));
@property (readonly) int32_t designCapacityMah __attribute__((swift_name("designCapacityMah")));
@property (readonly) int32_t fullChargeCapacityMah __attribute__((swift_name("fullChargeCapacityMah")));
@property (readonly) BOOL isCharging __attribute__((swift_name("isCharging")));
@property (readonly) int32_t remainingCapacityMah __attribute__((swift_name("remainingCapacityMah")));
@property (readonly) int32_t stateOfCharge __attribute__((swift_name("stateOfCharge")));
@property (readonly) int32_t stateOfHealth __attribute__((swift_name("stateOfHealth")));
@property (readonly) double temperatureCelsius __attribute__((swift_name("temperatureCelsius")));
@property (readonly) double voltage __attribute__((swift_name("voltage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BoundsPoint")))
@interface SIPCSDKBoundsPoint : SIPCSDKBase
- (instancetype)initWithX:(int32_t)x y:(int32_t)y __attribute__((swift_name("init(x:y:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKBoundsPoint *)doCopyX:(int32_t)x y:(int32_t)y __attribute__((swift_name("doCopy(x:y:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t x __attribute__((swift_name("x")));
@property (readonly) int32_t y __attribute__((swift_name("y")));
@end


/** Extended decoder centering mode. Window modes use the engine's existing rectangle. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CenteringMode")))
@interface SIPCSDKCenteringMode : SIPCSDKKotlinEnum<SIPCSDKCenteringMode *>
+ (instancetype)alloc __attribute__((unavailable));

/** Extended decoder centering mode. Window modes use the engine's existing rectangle. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) SIPCSDKCenteringModeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) SIPCSDKCenteringMode *disabled __attribute__((swift_name("disabled")));
@property (class, readonly) SIPCSDKCenteringMode *aroundAimer __attribute__((swift_name("aroundAimer")));
@property (class, readonly) SIPCSDKCenteringMode *window __attribute__((swift_name("window")));
@property (class, readonly) SIPCSDKCenteringMode *subImageWindow __attribute__((swift_name("subImageWindow")));
+ (SIPCSDKKotlinArray<SIPCSDKCenteringMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKCenteringMode *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t code __attribute__((swift_name("code")));
@property (readonly) NSString *label __attribute__((swift_name("label")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CenteringMode.Companion")))
@interface SIPCSDKCenteringModeCompanion : SIPCSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SIPCSDKCenteringModeCompanion *shared __attribute__((swift_name("shared")));
- (SIPCSDKCenteringMode * _Nullable)fromCodeCode:(int32_t)code __attribute__((swift_name("fromCode(code:)")));
@end


/** Permitted upper-left and lower-right centering-window corner coordinates, in pixels. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CenteringWindowLimits")))
@interface SIPCSDKCenteringWindowLimits : SIPCSDKBase
- (instancetype)initWithUlXMin:(int32_t)ulXMin ulXMax:(int32_t)ulXMax ulYMin:(int32_t)ulYMin ulYMax:(int32_t)ulYMax lrXMin:(int32_t)lrXMin lrXMax:(int32_t)lrXMax lrYMin:(int32_t)lrYMin lrYMax:(int32_t)lrYMax __attribute__((swift_name("init(ulXMin:ulXMax:ulYMin:ulYMax:lrXMin:lrXMax:lrYMin:lrYMax:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKCenteringWindowLimits *)doCopyUlXMin:(int32_t)ulXMin ulXMax:(int32_t)ulXMax ulYMin:(int32_t)ulYMin ulYMax:(int32_t)ulYMax lrXMin:(int32_t)lrXMin lrXMax:(int32_t)lrXMax lrYMin:(int32_t)lrYMin lrYMax:(int32_t)lrYMax __attribute__((swift_name("doCopy(ulXMin:ulXMax:ulYMin:ulYMax:lrXMin:lrXMax:lrYMin:lrYMax:)")));

/** Permitted upper-left and lower-right centering-window corner coordinates, in pixels. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Permitted upper-left and lower-right centering-window corner coordinates, in pixels. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Permitted upper-left and lower-right centering-window corner coordinates, in pixels. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t lrXMax __attribute__((swift_name("lrXMax")));
@property (readonly) int32_t lrXMin __attribute__((swift_name("lrXMin")));
@property (readonly) int32_t lrYMax __attribute__((swift_name("lrYMax")));
@property (readonly) int32_t lrYMin __attribute__((swift_name("lrYMin")));
@property (readonly) int32_t ulXMax __attribute__((swift_name("ulXMax")));
@property (readonly) int32_t ulXMin __attribute__((swift_name("ulXMin")));
@property (readonly) int32_t ulYMax __attribute__((swift_name("ulYMax")));
@property (readonly) int32_t ulYMin __attribute__((swift_name("ulYMin")));
@end


/** Observable phases of scanner discovery and connection. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConnectionState")))
@interface SIPCSDKConnectionState : SIPCSDKKotlinEnum<SIPCSDKConnectionState *>
+ (instancetype)alloc __attribute__((unavailable));

/** Observable phases of scanner discovery and connection. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKConnectionState *waitingfornfc __attribute__((swift_name("waitingfornfc")));
@property (class, readonly) SIPCSDKConnectionState *requestingbluetooth __attribute__((swift_name("requestingbluetooth")));
@property (class, readonly) SIPCSDKConnectionState *scanning __attribute__((swift_name("scanning")));
@property (class, readonly) SIPCSDKConnectionState *connecting __attribute__((swift_name("connecting")));
@property (class, readonly) SIPCSDKConnectionState *discoveringservices __attribute__((swift_name("discoveringservices")));
@property (class, readonly) SIPCSDKConnectionState *connected __attribute__((swift_name("connected")));
@property (class, readonly) SIPCSDKConnectionState *reconnecting __attribute__((swift_name("reconnecting")));
@property (class, readonly) SIPCSDKConnectionState *error __attribute__((swift_name("error")));
+ (SIPCSDKKotlinArray<SIPCSDKConnectionState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKConnectionState *> *entries __attribute__((swift_name("entries")));
@end


/** Decoder limits; firmware can reset them when the scan engine is reinitialized. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DecodeOptions")))
@interface SIPCSDKDecodeOptions : SIPCSDKBase
- (instancetype)initWithAttemptLimit:(int32_t)attemptLimit searchLimit:(int32_t)searchLimit callbackWaitTimeoutMs:(int32_t)callbackWaitTimeoutMs multiReadCount:(int32_t)multiReadCount __attribute__((swift_name("init(attemptLimit:searchLimit:callbackWaitTimeoutMs:multiReadCount:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKDecodeOptions *)doCopyAttemptLimit:(int32_t)attemptLimit searchLimit:(int32_t)searchLimit callbackWaitTimeoutMs:(int32_t)callbackWaitTimeoutMs multiReadCount:(int32_t)multiReadCount __attribute__((swift_name("doCopy(attemptLimit:searchLimit:callbackWaitTimeoutMs:multiReadCount:)")));

/** Decoder limits; firmware can reset them when the scan engine is reinitialized. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Decoder limits; firmware can reset them when the scan engine is reinitialized. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Decoder limits; firmware can reset them when the scan engine is reinitialized. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t attemptLimit __attribute__((swift_name("attemptLimit")));
@property (readonly) int32_t callbackWaitTimeoutMs __attribute__((swift_name("callbackWaitTimeoutMs")));
@property (readonly) int32_t multiReadCount __attribute__((swift_name("multiReadCount")));
@property (readonly) int32_t searchLimit __attribute__((swift_name("searchLimit")));
@end


/** Read-only device details and settings snapshot returned by command 0x58. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceDetails")))
@interface SIPCSDKDeviceDetails : SIPCSDKBase

/** Compares all bytes in the device-details block. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Hashes all bytes in the device-details block. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Returns the enabled state reported for [symbology], or false when it is unsupported. */
- (BOOL)isSymbologyEnabledSymbology:(SIPCSDKScannerSymbology *)symbology __attribute__((swift_name("isSymbologyEnabled(symbology:)")));

/** Enabled state reported for every individually supported barcode symbology. */
@property (readonly) NSDictionary<SIPCSDKScannerSymbology *, SIPCSDKBoolean *> *barcodeEnable __attribute__((swift_name("barcodeEnable")));

/** Battery charge percentage reported in the details block. */
@property (readonly) int32_t batteryPercent __attribute__((swift_name("batteryPercent")));

/** Whether the scanner beep is enabled. */
@property (readonly) BOOL beepEnabled __attribute__((swift_name("beepEnabled")));

/** Configured beep duration in milliseconds. */
@property (readonly) int32_t beepTimeMs __attribute__((swift_name("beepTimeMs")));

/** Whether channel sounding is enabled. */
@property (readonly) BOOL channelSoundingEnabled __attribute__((swift_name("channelSoundingEnabled")));

/** Configured idle timeout in minutes. */
@property (readonly) int32_t idleMinutes __attribute__((swift_name("idleMinutes")));

/** Raw firmware low-power flag. */
@property (readonly) int32_t lpFlag __attribute__((swift_name("lpFlag")));

/** Raw firmware power-off flag. */
@property (readonly) int32_t powerOffFlag __attribute__((swift_name("powerOffFlag")));

/** Configured automatic power-off time in seconds. */
@property (readonly) int32_t powerOffRtcSec __attribute__((swift_name("powerOffRtcSec")));

/** Defensive copy of the complete 256-byte details block. */
@property (readonly) SIPCSDKKotlinByteArray *raw __attribute__((swift_name("raw")));

/** Configured scan interval in milliseconds. */
@property (readonly) int32_t scanIntervalMs __attribute__((swift_name("scanIntervalMs")));

/** Configured scan timeout in milliseconds. */
@property (readonly) int32_t scanTimeoutMs __attribute__((swift_name("scanTimeoutMs")));

/** Typed scan work mode, or null when the firmware reports an unknown value. */
@property (readonly) SIPCSDKBarcodeScanMode * _Nullable scanWorkMode __attribute__((swift_name("scanWorkMode")));

/** Raw scan work-mode value reported by the firmware. */
@property (readonly) int32_t scanWorkModeValue __attribute__((swift_name("scanWorkModeValue")));

/** Whether scan vibration is enabled. */
@property (readonly) BOOL vibrateEnabled __attribute__((swift_name("vibrateEnabled")));
@end


/** Installed scan-engine identifier. Unknown numeric values are retained. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineId")))
@interface SIPCSDKEngineId : SIPCSDKBase
- (instancetype)initWithCode:(int32_t)code __attribute__((swift_name("init(code:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKEngineId *)doCopyCode:(int32_t)code __attribute__((swift_name("doCopy(code:)")));

/** Installed scan-engine identifier. Unknown numeric values are retained. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Installed scan-engine identifier. Unknown numeric values are retained. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Installed scan-engine identifier. Unknown numeric values are retained. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t code __attribute__((swift_name("code")));
@property (readonly) NSString *label __attribute__((swift_name("label")));
@end


/** Scan-engine family. Unrecognized codes map to [UNKNOWN]. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineType")))
@interface SIPCSDKEngineType : SIPCSDKKotlinEnum<SIPCSDKEngineType *>
+ (instancetype)alloc __attribute__((unavailable));

/** Scan-engine family. Unrecognized codes map to [UNKNOWN]. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) SIPCSDKEngineTypeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) SIPCSDKEngineType *unknown __attribute__((swift_name("unknown")));
@property (class, readonly) SIPCSDKEngineType *none __attribute__((swift_name("none")));
@property (class, readonly) SIPCSDKEngineType *imager __attribute__((swift_name("imager")));
@property (class, readonly) SIPCSDKEngineType *laser __attribute__((swift_name("laser")));
+ (SIPCSDKKotlinArray<SIPCSDKEngineType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKEngineType *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineType.Companion")))
@interface SIPCSDKEngineTypeCompanion : SIPCSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SIPCSDKEngineTypeCompanion *shared __attribute__((swift_name("shared")));
- (SIPCSDKEngineType *)fromCodeCode:(int32_t)code __attribute__((swift_name("fromCode(code:)")));
@end


/** Exposure control while acquiring an image. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExposureMode")))
@interface SIPCSDKExposureMode : SIPCSDKKotlinEnum<SIPCSDKExposureMode *>
+ (instancetype)alloc __attribute__((unavailable));

/** Exposure control while acquiring an image. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) SIPCSDKExposureModeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) SIPCSDKExposureMode *fixed __attribute__((swift_name("fixed")));
@property (class, readonly) SIPCSDKExposureMode *onChip __attribute__((swift_name("onChip")));
@property (class, readonly) SIPCSDKExposureMode *hhp __attribute__((swift_name("hhp")));
+ (SIPCSDKKotlinArray<SIPCSDKExposureMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKExposureMode *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t code __attribute__((swift_name("code")));
@property (readonly) NSString *label __attribute__((swift_name("label")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExposureMode.Companion")))
@interface SIPCSDKExposureModeCompanion : SIPCSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SIPCSDKExposureModeCompanion *shared __attribute__((swift_name("shared")));
- (SIPCSDKExposureMode * _Nullable)fromCodeCode:(int32_t)code __attribute__((swift_name("fromCode(code:)")));
@end


/** Exposure parameter and the decoder guide's accepted value range. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExposureParameter")))
@interface SIPCSDKExposureParameter : SIPCSDKKotlinEnum<SIPCSDKExposureParameter *>
+ (instancetype)alloc __attribute__((unavailable));

/** Exposure parameter and the decoder guide's accepted value range. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKExposureParameter *exposureMethod __attribute__((swift_name("exposureMethod")));
@property (class, readonly) SIPCSDKExposureParameter *targetValue __attribute__((swift_name("targetValue")));
@property (class, readonly) SIPCSDKExposureParameter *targetPercentile __attribute__((swift_name("targetPercentile")));
@property (class, readonly) SIPCSDKExposureParameter *targetAcceptGap __attribute__((swift_name("targetAcceptGap")));
@property (class, readonly) SIPCSDKExposureParameter *maxExposure __attribute__((swift_name("maxExposure")));
@property (class, readonly) SIPCSDKExposureParameter *maxGain __attribute__((swift_name("maxGain")));
@property (class, readonly) SIPCSDKExposureParameter *frameRate __attribute__((swift_name("frameRate")));
@property (class, readonly) SIPCSDKExposureParameter *conformImage __attribute__((swift_name("conformImage")));
@property (class, readonly) SIPCSDKExposureParameter *conformTries __attribute__((swift_name("conformTries")));
@property (class, readonly) SIPCSDKExposureParameter *specularExclusion __attribute__((swift_name("specularExclusion")));
@property (class, readonly) SIPCSDKExposureParameter *specularSaturation __attribute__((swift_name("specularSaturation")));
@property (class, readonly) SIPCSDKExposureParameter *specularLimit __attribute__((swift_name("specularLimit")));
@property (class, readonly) SIPCSDKExposureParameter *fixedExposure __attribute__((swift_name("fixedExposure")));
@property (class, readonly) SIPCSDKExposureParameter *fixedGain __attribute__((swift_name("fixedGain")));
@property (class, readonly) SIPCSDKExposureParameter *fixedFrameRate __attribute__((swift_name("fixedFrameRate")));
+ (SIPCSDKKotlinArray<SIPCSDKExposureParameter *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKExposureParameter *> *entries __attribute__((swift_name("entries")));
- (BOOL)acceptsValue:(int32_t)value __attribute__((swift_name("accepts(value:)")));
@property (readonly) int32_t id __attribute__((swift_name("id")));
@property (readonly) NSString *label __attribute__((swift_name("label")));
@property (readonly) int32_t max __attribute__((swift_name("max")));
@property (readonly) int32_t min __attribute__((swift_name("min")));
@end


/** Changes individual flag bits inside [com.ipcmobile.snapipcsdk.interfaces.ISymbology.update]. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlagEditor")))
@interface SIPCSDKFlagEditor : SIPCSDKBase
- (void)addFlag:(SIPCSDKKotlinArray<SIPCSDKSymbologyFlag *> *)flag __attribute__((swift_name("add(flag:)")));
- (void)removeFlag:(SIPCSDKKotlinArray<SIPCSDKSymbologyFlag *> *)flag __attribute__((swift_name("remove(flag:)")));
- (void)setFlag:(SIPCSDKSymbologyFlag *)flag on:(BOOL)on __attribute__((swift_name("set(flag:on:)")));
@end


/** Revision or identity string selector for the scan engine. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HsmRevision")))
@interface SIPCSDKHsmRevision : SIPCSDKKotlinEnum<SIPCSDKHsmRevision *>
+ (instancetype)alloc __attribute__((unavailable));

/** Revision or identity string selector for the scan engine. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKHsmRevision *api __attribute__((swift_name("api")));
@property (class, readonly) SIPCSDKHsmRevision *decoder __attribute__((swift_name("decoder")));
@property (class, readonly) SIPCSDKHsmRevision *decoderControl __attribute__((swift_name("decoderControl")));
@property (class, readonly) SIPCSDKHsmRevision *decThreads __attribute__((swift_name("decThreads")));
@property (class, readonly) SIPCSDKHsmRevision *decon __attribute__((swift_name("decon")));
@property (class, readonly) SIPCSDKHsmRevision *hardwareLayer __attribute__((swift_name("hardwareLayer")));
@property (class, readonly) SIPCSDKHsmRevision *scanDriver __attribute__((swift_name("scanDriver")));
@property (class, readonly) SIPCSDKHsmRevision *serialNumber __attribute__((swift_name("serialNumber")));
@property (class, readonly) SIPCSDKHsmRevision *psocMajor __attribute__((swift_name("psocMajor")));
@property (class, readonly) SIPCSDKHsmRevision *psocMinor __attribute__((swift_name("psocMinor")));
+ (SIPCSDKKotlinArray<SIPCSDKHsmRevision *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKHsmRevision *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *label __attribute__((swift_name("label")));
@property (readonly) int32_t selector __attribute__((swift_name("selector")));
@end


/** Container format of an image received from the scan engine. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImageFormat")))
@interface SIPCSDKImageFormat : SIPCSDKKotlinEnum<SIPCSDKImageFormat *>
+ (instancetype)alloc __attribute__((unavailable));

/** Container format of an image received from the scan engine. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKImageFormat *jpeg __attribute__((swift_name("jpeg")));
@property (class, readonly) SIPCSDKImageFormat *bmp __attribute__((swift_name("bmp")));
@property (class, readonly) SIPCSDKImageFormat *rawGray __attribute__((swift_name("rawGray")));
@property (class, readonly) SIPCSDKImageFormat *unknown __attribute__((swift_name("unknown")));
+ (SIPCSDKKotlinArray<SIPCSDKImageFormat *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKImageFormat *> *entries __attribute__((swift_name("entries")));
@end


/** Inclusive pixel region in the imager's coordinate system. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImageRegion")))
@interface SIPCSDKImageRegion : SIPCSDKBase
- (instancetype)initWithTop:(int32_t)top left:(int32_t)left right:(int32_t)right bottom:(int32_t)bottom __attribute__((swift_name("init(top:left:right:bottom:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) SIPCSDKImageRegionCompanion *companion __attribute__((swift_name("companion")));
- (SIPCSDKImageRegion *)doCopyTop:(int32_t)top left:(int32_t)left right:(int32_t)right bottom:(int32_t)bottom __attribute__((swift_name("doCopy(top:left:right:bottom:)")));

/** Inclusive pixel region in the imager's coordinate system. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Inclusive pixel region in the imager's coordinate system. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Inclusive pixel region in the imager's coordinate system. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t bottom __attribute__((swift_name("bottom")));
@property (readonly) int32_t left __attribute__((swift_name("left")));
@property (readonly) int32_t right __attribute__((swift_name("right")));
@property (readonly) int32_t top __attribute__((swift_name("top")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImageRegion.Companion")))
@interface SIPCSDKImageRegionCompanion : SIPCSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SIPCSDKImageRegionCompanion *shared __attribute__((swift_name("shared")));

/** Full frame for the standard 832 x 640 imager; other engines may need another region. */
@property (readonly) SIPCSDKImageRegion *FULL_832x640 __attribute__((swift_name("FULL_832x640")));
@end


/** Scan-engine details. [serialAndPart] is the raw concatenation returned by the scanner. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImagerProperties")))
@interface SIPCSDKImagerProperties : SIPCSDKBase
- (instancetype)initWithEngineId:(SIPCSDKEngineId *)engineId firmwareEngineId:(int32_t)firmwareEngineId firmwareMajor:(int32_t)firmwareMajor firmwareMinor:(int32_t)firmwareMinor serialAndPart:(NSString *)serialAndPart serialNumber:(NSString * _Nullable)serialNumber partNumber:(NSString * _Nullable)partNumber __attribute__((swift_name("init(engineId:firmwareEngineId:firmwareMajor:firmwareMinor:serialAndPart:serialNumber:partNumber:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKImagerProperties *)doCopyEngineId:(SIPCSDKEngineId *)engineId firmwareEngineId:(int32_t)firmwareEngineId firmwareMajor:(int32_t)firmwareMajor firmwareMinor:(int32_t)firmwareMinor serialAndPart:(NSString *)serialAndPart serialNumber:(NSString * _Nullable)serialNumber partNumber:(NSString * _Nullable)partNumber __attribute__((swift_name("doCopy(engineId:firmwareEngineId:firmwareMajor:firmwareMinor:serialAndPart:serialNumber:partNumber:)")));

/** Scan-engine details. [serialAndPart] is the raw concatenation returned by the scanner. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Scan-engine details. [serialAndPart] is the raw concatenation returned by the scanner. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Scan-engine details. [serialAndPart] is the raw concatenation returned by the scanner. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKEngineId *engineId __attribute__((swift_name("engineId")));
@property (readonly) int32_t firmwareEngineId __attribute__((swift_name("firmwareEngineId")));
@property (readonly) int32_t firmwareMajor __attribute__((swift_name("firmwareMajor")));
@property (readonly) int32_t firmwareMinor __attribute__((swift_name("firmwareMinor")));
@property (readonly) NSString * _Nullable partNumber __attribute__((swift_name("partNumber")));
@property (readonly) NSString *serialAndPart __attribute__((swift_name("serialAndPart")));
@property (readonly) NSString * _Nullable serialNumber __attribute__((swift_name("serialNumber")));
@end


/** Dimensions and byte count of the image held from the last decode. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LastImageInfo")))
@interface SIPCSDKLastImageInfo : SIPCSDKBase
- (instancetype)initWithColumns:(int32_t)columns rows:(int32_t)rows sizeBytes:(int64_t)sizeBytes __attribute__((swift_name("init(columns:rows:sizeBytes:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKLastImageInfo *)doCopyColumns:(int32_t)columns rows:(int32_t)rows sizeBytes:(int64_t)sizeBytes __attribute__((swift_name("doCopy(columns:rows:sizeBytes:)")));

/** Dimensions and byte count of the image held from the last decode. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Dimensions and byte count of the image held from the last decode. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Dimensions and byte count of the image held from the last decode. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t columns __attribute__((swift_name("columns")));
@property (readonly) int32_t rows __attribute__((swift_name("rows")));
@property (readonly) int64_t sizeBytes __attribute__((swift_name("sizeBytes")));
@end


/** Decoder-supported shortest and longest lengths for a range-capable format. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LengthLimits")))
@interface SIPCSDKLengthLimits : SIPCSDKBase
- (instancetype)initWithMin:(int64_t)min max:(int64_t)max __attribute__((swift_name("init(min:max:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKLengthLimits *)doCopyMin:(int64_t)min max:(int64_t)max __attribute__((swift_name("doCopy(min:max:)")));

/** Decoder-supported shortest and longest lengths for a range-capable format. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Decoder-supported shortest and longest lengths for a range-capable format. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Decoder-supported shortest and longest lengths for a range-capable format. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t max __attribute__((swift_name("max")));
@property (readonly) int64_t min __attribute__((swift_name("min")));
@end


/**
 * Colors accepted by the scanner's light-bar command.
 * @property wireValue Firmware byte used by command 0x09.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LightbarColor")))
@interface SIPCSDKLightbarColor : SIPCSDKKotlinEnum<SIPCSDKLightbarColor *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Colors accepted by the scanner's light-bar command.
 * @property wireValue Firmware byte used by command 0x09.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKLightbarColor *off __attribute__((swift_name("off")));
@property (class, readonly) SIPCSDKLightbarColor *red __attribute__((swift_name("red")));
@property (class, readonly) SIPCSDKLightbarColor *green __attribute__((swift_name("green")));
@property (class, readonly) SIPCSDKLightbarColor *blue __attribute__((swift_name("blue")));
+ (SIPCSDKKotlinArray<SIPCSDKLightbarColor *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKLightbarColor *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t wireValue __attribute__((swift_name("wireValue")));
@end


/** Aimer and illumination behavior while the scan engine is reading. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LightsMode")))
@interface SIPCSDKLightsMode : SIPCSDKKotlinEnum<SIPCSDKLightsMode *>
+ (instancetype)alloc __attribute__((unavailable));

/** Aimer and illumination behavior while the scan engine is reading. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) SIPCSDKLightsModeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) SIPCSDKLightsMode *off __attribute__((swift_name("off")));
@property (class, readonly) SIPCSDKLightsMode *aimerOnly __attribute__((swift_name("aimerOnly")));
@property (class, readonly) SIPCSDKLightsMode *illuminationOnly __attribute__((swift_name("illuminationOnly")));
@property (class, readonly) SIPCSDKLightsMode *illuminationAndAimer __attribute__((swift_name("illuminationAndAimer")));
@property (class, readonly) SIPCSDKLightsMode *aimerOnlyNonExposure __attribute__((swift_name("aimerOnlyNonExposure")));
+ (SIPCSDKKotlinArray<SIPCSDKLightsMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKLightsMode *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t code __attribute__((swift_name("code")));
@property (readonly) NSString *label __attribute__((swift_name("label")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LightsMode.Companion")))
@interface SIPCSDKLightsModeCompanion : SIPCSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SIPCSDKLightsModeCompanion *shared __attribute__((swift_name("shared")));
- (SIPCSDKLightsMode * _Nullable)fromCodeCode:(int32_t)code __attribute__((swift_name("fromCode(code:)")));
@end


/**
 * Firmware OCR polarity selection.
 * @property wireValue Encoded mode byte.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OcrMode")))
@interface SIPCSDKOcrMode : SIPCSDKKotlinEnum<SIPCSDKOcrMode *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Firmware OCR polarity selection.
 * @property wireValue Encoded mode byte.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKOcrMode *off __attribute__((swift_name("off")));
@property (class, readonly) SIPCSDKOcrMode *normalvideo __attribute__((swift_name("normalvideo")));
@property (class, readonly) SIPCSDKOcrMode *inverse __attribute__((swift_name("inverse")));
@property (class, readonly) SIPCSDKOcrMode *both __attribute__((swift_name("both")));
+ (SIPCSDKKotlinArray<SIPCSDKOcrMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKOcrMode *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t wireValue __attribute__((swift_name("wireValue")));
@end


/** OCR mode and template bitmask currently reported by the scan engine. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OcrSettings")))
@interface SIPCSDKOcrSettings : SIPCSDKBase
- (instancetype)initWithMode:(SIPCSDKOcrMode *)mode templates:(int32_t)templates __attribute__((swift_name("init(mode:templates:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKOcrSettings *)doCopyMode:(SIPCSDKOcrMode *)mode templates:(int32_t)templates __attribute__((swift_name("doCopy(mode:templates:)")));

/** OCR mode and template bitmask currently reported by the scan engine. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** OCR mode and template bitmask currently reported by the scan engine. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** OCR mode and template bitmask currently reported by the scan engine. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKOcrMode *mode __attribute__((swift_name("mode")));
@property (readonly) int32_t templates __attribute__((swift_name("templates")));
@end


/**
 * OCR template bit flags. Passport must not be combined with other templates.
 * @property mask Encoded template flag.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OcrTemplate")))
@interface SIPCSDKOcrTemplate : SIPCSDKKotlinEnum<SIPCSDKOcrTemplate *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * OCR template bit flags. Passport must not be combined with other templates.
 * @property mask Encoded template flag.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKOcrTemplate *user __attribute__((swift_name("user")));
@property (class, readonly) SIPCSDKOcrTemplate *passport __attribute__((swift_name("passport")));
@property (class, readonly) SIPCSDKOcrTemplate *isbn __attribute__((swift_name("isbn")));
@property (class, readonly) SIPCSDKOcrTemplate *pricefield __attribute__((swift_name("pricefield")));
@property (class, readonly) SIPCSDKOcrTemplate *micre13b __attribute__((swift_name("micre13b")));
+ (SIPCSDKKotlinArray<SIPCSDKOcrTemplate *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKOcrTemplate *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t mask __attribute__((swift_name("mask")));
@end


/** Custom OCR template text and its video mode. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OcrUserTemplate")))
@interface SIPCSDKOcrUserTemplate : SIPCSDKBase
- (instancetype)initWithMode:(SIPCSDKOcrMode *)mode template:(NSString *)template_ __attribute__((swift_name("init(mode:template:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKOcrUserTemplate *)doCopyMode:(SIPCSDKOcrMode *)mode template:(NSString *)template_ __attribute__((swift_name("doCopy(mode:template:)")));

/** Custom OCR template text and its video mode. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Custom OCR template text and its video mode. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Custom OCR template text and its video mode. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKOcrMode *mode __attribute__((swift_name("mode")));
@property (readonly, getter=template) NSString *template_ __attribute__((swift_name("template_")));
@end


/** Repeat-read confirmation for one decoder format. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Redundancy")))
@interface SIPCSDKRedundancy : SIPCSDKBase
- (instancetype)initWithEnabled:(BOOL)enabled count:(int32_t)count __attribute__((swift_name("init(enabled:count:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKRedundancy *)doCopyEnabled:(BOOL)enabled count:(int32_t)count __attribute__((swift_name("doCopy(enabled:count:)")));

/** Repeat-read confirmation for one decoder format. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Repeat-read confirmation for one decoder format. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Repeat-read confirmation for one decoder format. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t count __attribute__((swift_name("count")));
@property (readonly) BOOL enabled __attribute__((swift_name("enabled")));
@end


/** Image bytes and metadata from the scan engine. Stored-image reads also report exposure and gain. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerImage")))
@interface SIPCSDKScannerImage : SIPCSDKBase
- (instancetype)initWithData:(SIPCSDKKotlinByteArray *)data format:(SIPCSDKImageFormat *)format width:(int32_t)width height:(int32_t)height exposure:(SIPCSDKLong * _Nullable)exposure gain:(SIPCSDKLong * _Nullable)gain __attribute__((swift_name("init(data:format:width:height:exposure:gain:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKKotlinByteArray *data __attribute__((swift_name("data")));
@property (readonly) SIPCSDKLong * _Nullable exposure __attribute__((swift_name("exposure")));
@property (readonly) SIPCSDKImageFormat *format __attribute__((swift_name("format")));
@property (readonly) SIPCSDKLong * _Nullable gain __attribute__((swift_name("gain")));
@property (readonly) int32_t height __attribute__((swift_name("height")));
@property (readonly) int32_t width __attribute__((swift_name("width")));
@end


/**
 * Barcode formats understood by the scanner firmware.
 *
 * [id] is the byte used by the enable/disable command. It is different from the
 * Honeywell code returned with a decoded barcode.
 * @property displayName Human-readable name for settings screens.
 * @property deprecated True when current decoder firmware no longer supports the entry.
 * @property meta True for firmware control values that should not appear as individual formats.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerSymbology")))
@interface SIPCSDKScannerSymbology : SIPCSDKKotlinEnum<SIPCSDKScannerSymbology *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Barcode formats understood by the scanner firmware.
 *
 * [id] is the byte used by the enable/disable command. It is different from the
 * Honeywell code returned with a decoded barcode.
 * @property displayName Human-readable name for settings screens.
 * @property deprecated True when current decoder firmware no longer supports the entry.
 * @property meta True for firmware control values that should not appear as individual formats.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) SIPCSDKScannerSymbologyCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) SIPCSDKScannerSymbology *symAztec __attribute__((swift_name("symAztec")));
@property (class, readonly) SIPCSDKScannerSymbology *symCodabar __attribute__((swift_name("symCodabar")));
@property (class, readonly) SIPCSDKScannerSymbology *symCode11 __attribute__((swift_name("symCode11")));
@property (class, readonly) SIPCSDKScannerSymbology *symCode128 __attribute__((swift_name("symCode128")));
@property (class, readonly) SIPCSDKScannerSymbology *symCode39 __attribute__((swift_name("symCode39")));
@property (class, readonly) SIPCSDKScannerSymbology *symCode49 __attribute__((swift_name("symCode49")));
@property (class, readonly) SIPCSDKScannerSymbology *symCode93 __attribute__((swift_name("symCode93")));
@property (class, readonly) SIPCSDKScannerSymbology *symComposite __attribute__((swift_name("symComposite")));
@property (class, readonly) SIPCSDKScannerSymbology *symDatamatrix __attribute__((swift_name("symDatamatrix")));
@property (class, readonly) SIPCSDKScannerSymbology *symEan8 __attribute__((swift_name("symEan8")));
@property (class, readonly) SIPCSDKScannerSymbology *symEan13 __attribute__((swift_name("symEan13")));
@property (class, readonly) SIPCSDKScannerSymbology *symInt25 __attribute__((swift_name("symInt25")));
@property (class, readonly) SIPCSDKScannerSymbology *symMaxicode __attribute__((swift_name("symMaxicode")));
@property (class, readonly) SIPCSDKScannerSymbology *symMicropdf __attribute__((swift_name("symMicropdf")));
@property (class, readonly) SIPCSDKScannerSymbology *symOcr __attribute__((swift_name("symOcr")));
@property (class, readonly) SIPCSDKScannerSymbology *symPdf417 __attribute__((swift_name("symPdf417")));
@property (class, readonly) SIPCSDKScannerSymbology *symPostnet __attribute__((swift_name("symPostnet")));
@property (class, readonly) SIPCSDKScannerSymbology *symQr __attribute__((swift_name("symQr")));
@property (class, readonly) SIPCSDKScannerSymbology *symRss __attribute__((swift_name("symRss")));
@property (class, readonly) SIPCSDKScannerSymbology *symUpca __attribute__((swift_name("symUpca")));
@property (class, readonly) SIPCSDKScannerSymbology *symUpce0 __attribute__((swift_name("symUpce0")));
@property (class, readonly) SIPCSDKScannerSymbology *symUpce1 __attribute__((swift_name("symUpce1")));
@property (class, readonly) SIPCSDKScannerSymbology *symIsbt __attribute__((swift_name("symIsbt")));
@property (class, readonly) SIPCSDKScannerSymbology *symBpo __attribute__((swift_name("symBpo")));
@property (class, readonly) SIPCSDKScannerSymbology *symCanpost __attribute__((swift_name("symCanpost")));
@property (class, readonly) SIPCSDKScannerSymbology *symAuspost __attribute__((swift_name("symAuspost")));
@property (class, readonly) SIPCSDKScannerSymbology *symIata25 __attribute__((swift_name("symIata25")));
@property (class, readonly) SIPCSDKScannerSymbology *symCodablock __attribute__((swift_name("symCodablock")));
@property (class, readonly) SIPCSDKScannerSymbology *symJapost __attribute__((swift_name("symJapost")));
@property (class, readonly) SIPCSDKScannerSymbology *symPlanet __attribute__((swift_name("symPlanet")));
@property (class, readonly) SIPCSDKScannerSymbology *symDutchpost __attribute__((swift_name("symDutchpost")));
@property (class, readonly) SIPCSDKScannerSymbology *symMsi __attribute__((swift_name("symMsi")));
@property (class, readonly) SIPCSDKScannerSymbology *symTlcode39 __attribute__((swift_name("symTlcode39")));
@property (class, readonly) SIPCSDKScannerSymbology *symTrioptic __attribute__((swift_name("symTrioptic")));
@property (class, readonly) SIPCSDKScannerSymbology *symCode32 __attribute__((swift_name("symCode32")));
@property (class, readonly) SIPCSDKScannerSymbology *symStrt25 __attribute__((swift_name("symStrt25")));
@property (class, readonly) SIPCSDKScannerSymbology *symMatrix25 __attribute__((swift_name("symMatrix25")));
@property (class, readonly) SIPCSDKScannerSymbology *symPlessey __attribute__((swift_name("symPlessey")));
@property (class, readonly) SIPCSDKScannerSymbology *symChinapost __attribute__((swift_name("symChinapost")));
@property (class, readonly) SIPCSDKScannerSymbology *symKoreapost __attribute__((swift_name("symKoreapost")));
@property (class, readonly) SIPCSDKScannerSymbology *symTelepen __attribute__((swift_name("symTelepen")));
@property (class, readonly) SIPCSDKScannerSymbology *symCode16k __attribute__((swift_name("symCode16k")));
@property (class, readonly) SIPCSDKScannerSymbology *symPosicode __attribute__((swift_name("symPosicode")));
@property (class, readonly) SIPCSDKScannerSymbology *symCouponcode __attribute__((swift_name("symCouponcode")));
@property (class, readonly) SIPCSDKScannerSymbology *symUsps4cb __attribute__((swift_name("symUsps4cb")));
@property (class, readonly) SIPCSDKScannerSymbology *symIdtag __attribute__((swift_name("symIdtag")));
@property (class, readonly) SIPCSDKScannerSymbology *symLabel __attribute__((swift_name("symLabel")));
@property (class, readonly) SIPCSDKScannerSymbology *symGs1128 __attribute__((swift_name("symGs1128")));
@property (class, readonly) SIPCSDKScannerSymbology *symHanxin __attribute__((swift_name("symHanxin")));
@property (class, readonly) SIPCSDKScannerSymbology *symGridmatrix __attribute__((swift_name("symGridmatrix")));
@property (class, readonly) SIPCSDKScannerSymbology *symPostals __attribute__((swift_name("symPostals")));
@property (class, readonly) SIPCSDKScannerSymbology *symUsPostals1 __attribute__((swift_name("symUsPostals1")));
@property (class, readonly) SIPCSDKScannerSymbology *symDotcode __attribute__((swift_name("symDotcode")));
@property (class, readonly) SIPCSDKScannerSymbology *numSymbologies __attribute__((swift_name("numSymbologies")));
@property (class, readonly) SIPCSDKScannerSymbology *symAll __attribute__((swift_name("symAll")));
+ (SIPCSDKKotlinArray<SIPCSDKScannerSymbology *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKScannerSymbology *> *entries __attribute__((swift_name("entries")));
@property (readonly) BOOL deprecated __attribute__((swift_name("deprecated")));
@property (readonly) NSString *displayName __attribute__((swift_name("displayName")));

/** Firmware byte used in command 0x5D and the MENU_INFO array. */
@property (readonly) int32_t id __attribute__((swift_name("id")));
@property (readonly) BOOL meta __attribute__((swift_name("meta")));
@end


/** Provides the supported UI catalogue and firmware-ID lookup. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerSymbology.Companion")))
@interface SIPCSDKScannerSymbologyCompanion : SIPCSDKBase
+ (instancetype)alloc __attribute__((unavailable));

/** Provides the supported UI catalogue and firmware-ID lookup. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SIPCSDKScannerSymbologyCompanion *shared __attribute__((swift_name("shared")));

/** Resolves a firmware setting ID, including [SYM_ALL], or returns null. */
- (SIPCSDKScannerSymbology * _Nullable)fromIdId:(int32_t)id __attribute__((swift_name("fromId(id:)")));

/** Special firmware value used to enable or disable every symbology. */
@property (readonly) SIPCSDKScannerSymbology *All __attribute__((swift_name("All")));

/** Individual formats supported by current decoder firmware, sorted for display. */
@property (readonly) NSArray<SIPCSDKScannerSymbology *> *Supported __attribute__((swift_name("Supported")));
@end


/** Linear decoder priority; firmware behavior needs device verification. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScanningMode")))
@interface SIPCSDKScanningMode : SIPCSDKKotlinEnum<SIPCSDKScanningMode *>
+ (instancetype)alloc __attribute__((unavailable));

/** Linear decoder priority; firmware behavior needs device verification. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKScanningMode *fullOnly __attribute__((swift_name("fullOnly")));
@property (class, readonly) SIPCSDKScanningMode *fastFull __attribute__((swift_name("fastFull")));
+ (SIPCSDKKotlinArray<SIPCSDKScanningMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKScanningMode *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t code __attribute__((swift_name("code")));
@property (readonly) NSString *label __attribute__((swift_name("label")));
@end


/** Debug overlay drawn by the decoder on its image. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ShowDecodeWindow")))
@interface SIPCSDKShowDecodeWindow : SIPCSDKKotlinEnum<SIPCSDKShowDecodeWindow *>
+ (instancetype)alloc __attribute__((unavailable));

/** Debug overlay drawn by the decoder on its image. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) SIPCSDKShowDecodeWindowCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) SIPCSDKShowDecodeWindow *off __attribute__((swift_name("off")));
@property (class, readonly) SIPCSDKShowDecodeWindow *white __attribute__((swift_name("white")));
@property (class, readonly) SIPCSDKShowDecodeWindow *black __attribute__((swift_name("black")));
+ (SIPCSDKKotlinArray<SIPCSDKShowDecodeWindow *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKShowDecodeWindow *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t code __attribute__((swift_name("code")));
@property (readonly) NSString *label __attribute__((swift_name("label")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ShowDecodeWindow.Companion")))
@interface SIPCSDKShowDecodeWindowCompanion : SIPCSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SIPCSDKShowDecodeWindowCompanion *shared __attribute__((swift_name("shared")));
- (SIPCSDKShowDecodeWindow * _Nullable)fromCodeCode:(int32_t)code __attribute__((swift_name("fromCode(code:)")));
@end


/** Current HSM settings for one format. Lengths are null when the format has flags only. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SymbologyConfig")))
@interface SIPCSDKSymbologyConfig : SIPCSDKBase
- (instancetype)initWithSymbology:(SIPCSDKScannerSymbology *)symbology flags:(int32_t)flags minLength:(SIPCSDKInt * _Nullable)minLength maxLength:(SIPCSDKInt * _Nullable)maxLength __attribute__((swift_name("init(symbology:flags:minLength:maxLength:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKSymbologyConfig *)doCopySymbology:(SIPCSDKScannerSymbology *)symbology flags:(int32_t)flags minLength:(SIPCSDKInt * _Nullable)minLength maxLength:(SIPCSDKInt * _Nullable)maxLength __attribute__((swift_name("doCopy(symbology:flags:minLength:maxLength:)")));

/** Current HSM settings for one format. Lengths are null when the format has flags only. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (BOOL)hasFlag:(SIPCSDKSymbologyFlag *)flag __attribute__((swift_name("has(flag:)")));

/** Current HSM settings for one format. Lengths are null when the format has flags only. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Current HSM settings for one format. Lengths are null when the format has flags only. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t flags __attribute__((swift_name("flags")));
@property (readonly) SIPCSDKInt * _Nullable maxLength __attribute__((swift_name("maxLength")));
@property (readonly) SIPCSDKInt * _Nullable minLength __attribute__((swift_name("minLength")));
@property (readonly) SIPCSDKScannerSymbology *symbology __attribute__((swift_name("symbology")));
@end


/** Honeywell HSM flag bits for one barcode format. A decoder may ignore inapplicable bits. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SymbologyFlag")))
@interface SIPCSDKSymbologyFlag : SIPCSDKKotlinEnum<SIPCSDKSymbologyFlag *>
+ (instancetype)alloc __attribute__((unavailable));

/** Honeywell HSM flag bits for one barcode format. A decoder may ignore inapplicable bits. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SIPCSDKSymbologyFlag *enable __attribute__((swift_name("enable")));
@property (class, readonly) SIPCSDKSymbologyFlag *checkEnable __attribute__((swift_name("checkEnable")));
@property (class, readonly) SIPCSDKSymbologyFlag *checkTransmit __attribute__((swift_name("checkTransmit")));
@property (class, readonly) SIPCSDKSymbologyFlag *startStopTransmit __attribute__((swift_name("startStopTransmit")));
@property (class, readonly) SIPCSDKSymbologyFlag *appendMode __attribute__((swift_name("appendMode")));
@property (class, readonly) SIPCSDKSymbologyFlag *fullAscii __attribute__((swift_name("fullAscii")));
@property (class, readonly) SIPCSDKSymbologyFlag *numSysTransmit __attribute__((swift_name("numSysTransmit")));
@property (class, readonly) SIPCSDKSymbologyFlag *addenda2Digit __attribute__((swift_name("addenda2Digit")));
@property (class, readonly) SIPCSDKSymbologyFlag *addenda5Digit __attribute__((swift_name("addenda5Digit")));
@property (class, readonly) SIPCSDKSymbologyFlag *addendaRequired __attribute__((swift_name("addendaRequired")));
@property (class, readonly) SIPCSDKSymbologyFlag *addendaSeparator __attribute__((swift_name("addendaSeparator")));
@property (class, readonly) SIPCSDKSymbologyFlag *expandedUpce __attribute__((swift_name("expandedUpce")));
@property (class, readonly) SIPCSDKSymbologyFlag *upce1Enable __attribute__((swift_name("upce1Enable")));
@property (class, readonly) SIPCSDKSymbologyFlag *compositeUpc __attribute__((swift_name("compositeUpc")));
@property (class, readonly) SIPCSDKSymbologyFlag *aztecRune __attribute__((swift_name("aztecRune")));
@property (class, readonly) SIPCSDKSymbologyFlag *australianBarWidth __attribute__((swift_name("australianBarWidth")));
@property (class, readonly) SIPCSDKSymbologyFlag *rseEnable __attribute__((swift_name("rseEnable")));
@property (class, readonly) SIPCSDKSymbologyFlag *rslEnable __attribute__((swift_name("rslEnable")));
@property (class, readonly) SIPCSDKSymbologyFlag *rssEnable __attribute__((swift_name("rssEnable")));
@property (class, readonly) SIPCSDKSymbologyFlag *telepenOldStyle __attribute__((swift_name("telepenOldStyle")));
@property (class, readonly) SIPCSDKSymbologyFlag *posicodeLimited1 __attribute__((swift_name("posicodeLimited1")));
@property (class, readonly) SIPCSDKSymbologyFlag *posicodeLimited2 __attribute__((swift_name("posicodeLimited2")));
@property (class, readonly) SIPCSDKSymbologyFlag *codabarConcatenate __attribute__((swift_name("codabarConcatenate")));
+ (SIPCSDKKotlinArray<SIPCSDKSymbologyFlag *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SIPCSDKSymbologyFlag *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t bit __attribute__((swift_name("bit")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface SIPCSDKKotlinThrowable : SIPCSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (SIPCSDKKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) SIPCSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface SIPCSDKKotlinException : SIPCSDKKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * An asynchronous data stream that sequentially emits values and completes normally or with an exception.
 *
 * _Intermediate operators_ on the flow such as [map], [filter], [take], [zip], etc are functions that are
 * applied to the _upstream_ flow or flows and return a _downstream_ flow where further operators can be applied to.
 * Intermediate operations do not execute any code in the flow and are not suspending functions themselves.
 * They only set up a chain of operations for future execution and quickly return.
 * This is known as a _cold flow_ property.
 *
 * _Terminal operators_ on the flow are either suspending functions such as [collect], [single], [reduce], [toList], etc.
 * or [launchIn] operator that starts collection of the flow in the given scope.
 * They are applied to the upstream flow and trigger execution of all operations.
 * Execution of the flow is also called _collecting the flow_  and is always performed in a suspending manner
 * without actual blocking. Terminal operators complete normally or exceptionally depending on successful or failed
 * execution of all the flow operations in the upstream. The most basic terminal operator is [collect], for example:
 *
 * ```
 * try {
 *     flow.collect { value ->
 *         println("Received $value")
 *     }
 * } catch (e: Exception) {
 *     println("The flow has thrown an exception: $e")
 * }
 * ```
 *
 * By default, flows are _sequential_ and all flow operations are executed sequentially in the same coroutine,
 * with an exception for a few operations specifically designed to introduce concurrency into flow
 * execution such as [buffer] and [flatMapMerge]. See their documentation for details.
 *
 * The `Flow` interface does not carry information whether a flow is a _cold_ stream that can be collected repeatedly and
 * triggers execution of the same code every time it is collected, or if it is a _hot_ stream that emits different
 * values from the same running source on each collection. Usually flows represent _cold_ streams, but
 * there is a [SharedFlow] subtype that represents _hot_ streams. In addition to that, any flow can be turned
 * into a _hot_ one by the [stateIn] and [shareIn] operators, or by converting the flow into a hot channel
 * via the [produceIn] operator.
 *
 * ### Flow builders
 *
 * There are the following basic ways to create a flow:
 *
 * - [flowOf(...)][flowOf] functions to create a flow from a fixed set of values.
 * - [asFlow()][asFlow] extension functions on various types to convert them into flows.
 * - [flow { ... }][flow] builder function to construct arbitrary flows from
 *   sequential calls to [emit][FlowCollector.emit] function.
 * - [channelFlow { ... }][channelFlow] builder function to construct arbitrary flows from
 *   potentially concurrent calls to the [send][kotlinx.coroutines.channels.SendChannel.send] function.
 * - [MutableStateFlow] and [MutableSharedFlow] define the corresponding constructor functions to create
 *   a _hot_ flow that can be directly updated.
 *
 * ### Flow constraints
 *
 * All implementations of the `Flow` interface must adhere to two key properties described in detail below:
 *
 * - Context preservation.
 * - Exception transparency.
 *
 * These properties ensure the ability to perform local reasoning about the code with flows and modularize the code
 * in such a way that upstream flow emitters can be developed separately from downstream flow collectors.
 * A user of a flow does not need to be aware of implementation details of the upstream flows it uses.
 *
 * ### Context preservation
 *
 * The flow has a context preservation property: it encapsulates its own execution context and never propagates or leaks
 * it downstream, thus making reasoning about the execution context of particular transformations or terminal
 * operations trivial.
 *
 * There is only one way to change the context of a flow: the [flowOn][Flow.flowOn] operator
 * that changes the upstream context ("everything above the `flowOn` operator").
 * For additional information refer to its documentation.
 *
 * This reasoning can be demonstrated in practice:
 *
 * ```
 * val flowA = flowOf(1, 2, 3)
 *     .map { it + 1 } // Will be executed in ctxA
 *     .flowOn(ctxA) // Changes the upstream context: flowOf and map
 *
 * // Now we have a context-preserving flow: it is executed somewhere but this information is encapsulated in the flow itself
 *
 * val filtered = flowA // ctxA is encapsulated in flowA
 *    .filter { it == 3 } // Pure operator without a context yet
 *
 * withContext(Dispatchers.Main) {
 *     // All non-encapsulated operators will be executed in Main: filter and single
 *     val result = filtered.single()
 *     myUi.text = result
 * }
 * ```
 *
 * From the implementation point of view, it means that all flow implementations should
 * only emit from the same coroutine context.
 * This constraint is efficiently enforced by the default [flow] builder.
 * The [flow] builder should be used if the flow implementation does not start any coroutines.
 * Its implementation prevents most of the development mistakes:
 *
 * ```
 * val myFlow = flow {
 *     // GlobalScope.launch { // is prohibited
 *     // launch(Dispatchers.IO) { // is prohibited
 *     // withContext(CoroutineName("myFlow")) { // is prohibited
 *     emit(1) // OK
 *     coroutineScope {
 *         emit(2) // OK -- still the same coroutine
 *     }
 * }
 * ```
 *
 * Use [channelFlow] if the collection and emission of a flow are to be separated into multiple coroutines.
 * It encapsulates all the context preservation work and allows you to focus on your
 * domain-specific problem, rather than invariant implementation details.
 * It is possible to use any combination of coroutine builders from within [channelFlow].
 *
 * If you are looking for performance and are sure that no concurrent emits and context jumps will happen,
 * the [flow] builder can be used alongside a [coroutineScope] or [supervisorScope] instead:
 * - Scoped primitive should be used to provide a [CoroutineScope].
 * - Changing the context of emission is prohibited, no matter whether it is `withContext(ctx)` or
 *   a builder argument (e.g. `launch(ctx)`).
 * - Collecting another flow from a separate context is allowed, but it has the same effect as
 *   applying the [flowOn] operator to that flow, which is more efficient.
 *
 * ### Exception transparency
 *
 * When `emit` or `emitAll` throws, the Flow implementations must immediately stop emitting new values and finish with an exception.
 * For diagnostics or application-specific purposes, the exception may be different from the one thrown by the emit operation,
 * suppressing the original exception as discussed below.
 * If there is a need to emit values after the downstream failed, please use the [catch][Flow.catch] operator.
 *
 * The [catch][Flow.catch] operator only catches upstream exceptions, but passes
 * all downstream exceptions. Similarly, terminal operators like [collect][Flow.collect]
 * throw any unhandled exceptions that occur in their code or in upstream flows, for example:
 *
 * ```
 * flow { emitData() }
 *     .map { computeOne(it) }
 *     .catch { ... } // catches exceptions in emitData and computeOne
 *     .map { computeTwo(it) }
 *     .collect { process(it) } // throws exceptions from process and computeTwo
 * ```
 * The same reasoning can be applied to the [onCompletion] operator that is a declarative replacement for the `finally` block.
 *
 * All exception-handling Flow operators follow the principle of exception suppression:
 *
 * If the upstream flow throws an exception during its completion when the downstream exception has been thrown,
 * the downstream exception becomes superseded and suppressed by the upstream exception, being a semantic
 * equivalent of throwing from `finally` block. However, this doesn't affect the operation of the exception-handling operators,
 * which consider the downstream exception to be the root cause and behave as if the upstream didn't throw anything.
 *
 * Failure to adhere to the exception transparency requirement can lead to strange behaviors which make
 * it hard to reason about the code because an exception in the `collect { ... }` could be somehow "caught"
 * by an upstream flow, limiting the ability of local reasoning about the code.
 *
 * Flow machinery enforces exception transparency at runtime and throws [IllegalStateException] on any attempt to emit a value,
 * if an exception has been thrown on previous attempt.
 *
 * ### Reactive streams
 *
 * Flow is [Reactive Streams](http://www.reactive-streams.org/) compliant, you can safely interop it with
 * reactive streams using `Flow.asPublisher` and `Publisher.asFlow` from `kotlinx-coroutines-reactive` module.
 *
 * ### Not stable for inheritance
 *
 * **The `Flow` interface is not stable for inheritance in 3rd party libraries**, as new methods
 * might be added to this interface in the future, but is stable for use.
 *
 * Use the `flow { ... }` builder function to create an implementation, or extend [AbstractFlow].
 * These implementations ensure that the context preservation property is not violated, and prevent most
 * of the developer mistakes related to concurrency, inconsistent flow dispatchers, and cancellation.
 */
__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol SIPCSDKKotlinx_coroutines_coreFlow
@required

/**
 * Accepts the given [collector] and [emits][FlowCollector.emit] values into it.
 *
 * This method can be used along with SAM-conversion of [FlowCollector]:
 * ```
 * myFlow.collect { value -> println("Collected $value") }
 * ```
 *
 * ### Method inheritance
 *
 * To ensure the context preservation property, it is not recommended implementing this method directly.
 * Instead, [AbstractFlow] can be used as the base type to properly ensure flow's properties.
 *
 * All default flow implementations ensure context preservation and exception transparency properties on a best-effort basis
 * and throw [IllegalStateException] if a violation was detected.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<SIPCSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end


/**
 * A _hot_ [Flow] that shares emitted values among all its collectors in a broadcast fashion, so that all collectors
 * get all emitted values. A shared flow is called _hot_ because its active instance exists independently of the
 * presence of collectors. This is opposed to a regular [Flow], such as defined by the [`flow { ... }`][flow] function,
 * which is _cold_ and is started separately for each collector.
 *
 * **Shared flow never completes**. A call to [Flow.collect] on a shared flow never completes normally, and
 * neither does a coroutine started by the [Flow.launchIn] function. An active collector of a shared flow is called a _subscriber_.
 *
 * A subscriber of a shared flow can be cancelled. This usually happens when the scope in which the coroutine is running
 * is cancelled. A subscriber to a shared flow is always [cancellable][Flow.cancellable], and checks for
 * cancellation before each emission. Note that most terminal operators like [Flow.toList] would also not complete,
 * when applied to a shared flow, but flow-truncating operators like [Flow.take] and [Flow.takeWhile] can be used on a
 * shared flow to turn it into a completing one.
 *
 * A [mutable shared flow][MutableSharedFlow] is created using the [MutableSharedFlow(...)] constructor function.
 * Its state can be updated by [emitting][MutableSharedFlow.emit] values to it and performing other operations.
 * See the [MutableSharedFlow] documentation for details.
 *
 * [SharedFlow] is useful for broadcasting events that happen inside an application to subscribers that can come and go.
 * For example, the following class encapsulates an event bus that distributes events to all subscribers
 * in a _rendezvous_ manner, suspending until all subscribers receive emitted event:
 *
 * ```
 * class EventBus {
 *     private val _events = MutableSharedFlow<Event>() // private mutable shared flow
 *     val events = _events.asSharedFlow() // publicly exposed as read-only shared flow
 *
 *     suspend fun produceEvent(event: Event) {
 *         _events.emit(event) // suspends until all subscribers receive it
 *     }
 * }
 * ```
 *
 * As an alternative to the above usage with the `MutableSharedFlow(...)` constructor function,
 * any _cold_ [Flow] can be converted to a shared flow using the [shareIn] operator.
 *
 * There is a specialized implementation of shared flow for the case where the most recent state value needs
 * to be shared. See [StateFlow] for details.
 *
 * ### Replay cache and buffer
 *
 * A shared flow keeps a specific number of the most recent values in its _replay cache_. Every new subscriber first
 * gets the values from the replay cache and then gets new emitted values. The maximum size of the replay cache is
 * specified when the shared flow is created by the `replay` parameter. A snapshot of the current replay cache
 * is available via the [replayCache] property and it can be reset with the [MutableSharedFlow.resetReplayCache] function.
 *
 * A replay cache also provides buffer for emissions to the shared flow, allowing slow subscribers to
 * get values from the buffer without suspending emitters. The buffer space determines how much slow subscribers
 * can lag from the fast ones. When creating a shared flow, additional buffer capacity beyond replay can be reserved
 * using the `extraBufferCapacity` parameter.
 *
 * A shared flow with a buffer can be configured to avoid suspension of emitters on buffer overflow using
 * the `onBufferOverflow` parameter, which is equal to one of the entries of the [BufferOverflow] enum. When a strategy other
 * than [SUSPENDED][BufferOverflow.SUSPEND] is configured, emissions to the shared flow never suspend.
 *
 * **Buffer overflow condition can happen only when there is at least one subscriber that is not ready to accept
 * the new value.**  In the absence of subscribers only the most recent `replay` values are stored and the buffer
 * overflow behavior is never triggered and has no effect. In particular, in the absence of subscribers emitter never
 * suspends despite [BufferOverflow.SUSPEND] option and [BufferOverflow.DROP_LATEST] option does not have effect either.
 * Essentially, the behavior in the absence of subscribers is always similar to [BufferOverflow.DROP_OLDEST],
 * but the buffer is just of `replay` size (without any `extraBufferCapacity`).
 *
 * ### Unbuffered shared flow
 *
 * A default implementation of a shared flow that is created with `MutableSharedFlow()` constructor function
 * without parameters has no replay cache nor additional buffer.
 * [emit][MutableSharedFlow.emit] call to such a shared flow suspends until all subscribers receive the emitted value
 * and returns immediately if there are no subscribers.
 * Thus, [tryEmit][MutableSharedFlow.tryEmit] call succeeds and returns `true` only if
 * there are no subscribers (in which case the emitted value is immediately lost).
 *
 * ### SharedFlow vs BroadcastChannel
 *
 * Conceptually shared flow is similar to [BroadcastChannel][BroadcastChannel]
 * and is designed to completely replace it.
 * It has the following important differences:
 *
 * - `SharedFlow` is simpler, because it does not have to implement all the [Channel] APIs, which allows
 *   for faster and simpler implementation.
 * - `SharedFlow` supports configurable replay and buffer overflow strategy.
 * - `SharedFlow` has a clear separation into a read-only `SharedFlow` interface and a [MutableSharedFlow].
 * - `SharedFlow` cannot be closed like `BroadcastChannel` and can never represent a failure.
 *   All errors and completion signals should be explicitly _materialized_ if needed.
 *
 * To migrate [BroadcastChannel] usage to [SharedFlow], start by replacing usages of the `BroadcastChannel(capacity)`
 * constructor with `MutableSharedFlow(0, extraBufferCapacity=capacity)` (broadcast channel does not replay
 * values to new subscribers). Replace [send][BroadcastChannel.send] and [trySend][BroadcastChannel.trySend] calls
 * with [emit][MutableStateFlow.emit] and [tryEmit][MutableStateFlow.tryEmit], and convert subscribers' code to flow operators.
 *
 * ### Concurrency
 *
 * All methods of shared flow are **thread-safe** and can be safely invoked from concurrent coroutines without
 * external synchronization.
 *
 * ### Operator fusion
 *
 * Application of [flowOn][Flow.flowOn], [buffer] with [RENDEZVOUS][Channel.RENDEZVOUS] capacity,
 * or [cancellable] operators to a shared flow has no effect.
 *
 * ### Implementation notes
 *
 * Shared flow implementation uses a lock to ensure thread-safety, but suspending collector and emitter coroutines are
 * resumed outside of this lock to avoid deadlocks when using unconfined coroutines. Adding new subscribers
 * has `O(1)` amortized cost, but emitting has `O(N)` cost, where `N` is the number of subscribers.
 *
 * ### Not stable for inheritance
 *
 * **The `SharedFlow` interface is not stable for inheritance in 3rd party libraries**, as new methods
 * might be added to this interface in the future, but is stable for use.
 * Use the `MutableSharedFlow(replay, ...)` constructor function to create an implementation.
 *
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSharedFlow")))
@protocol SIPCSDKKotlinx_coroutines_coreSharedFlow <SIPCSDKKotlinx_coroutines_coreFlow>
@required

/**
 * A snapshot of the replay cache.
 */
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface SIPCSDKKotlinRuntimeException : SIPCSDKKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface SIPCSDKKotlinIllegalStateException : SIPCSDKKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface SIPCSDKKotlinCancellationException : SIPCSDKKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(SIPCSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface SIPCSDKKotlinPair<__covariant A, __covariant B> : SIPCSDKBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (SIPCSDKKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface SIPCSDKKotlinEnumCompanion : SIPCSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SIPCSDKKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface SIPCSDKKotlinArray<T> : SIPCSDKBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(SIPCSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<SIPCSDKKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface SIPCSDKKotlinByteArray : SIPCSDKBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(SIPCSDKByte *(^)(SIPCSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (SIPCSDKKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end


/**
 * [FlowCollector] is used as an intermediate or a terminal collector of the flow and represents
 * an entity that accepts values emitted by the [Flow].
 *
 * This interface should usually not be implemented directly, but rather used as a receiver in a [flow] builder when implementing a custom operator,
 * or with SAM-conversion.
 * Implementations of this interface are not thread-safe.
 *
 * Example of usage:
 *
 * ```
 * val flow = getMyEvents()
 * try {
 *     flow.collect { value ->
 *         println("Received $value")
 *     }
 *     println("My events are consumed successfully")
 * } catch (e: Throwable) {
 *     println("Exception from the flow: $e")
 * }
 * ```
 */
__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol SIPCSDKKotlinx_coroutines_coreFlowCollector
@required

/**
 * Collects the value emitted by the upstream.
 * This method is not thread-safe and should not be invoked concurrently.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol SIPCSDKKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface SIPCSDKKotlinByteIterator : SIPCSDKBase <SIPCSDKKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (SIPCSDKByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
