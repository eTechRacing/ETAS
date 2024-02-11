/* Copyright 2019-2021 The MathWorks, Inc. */

#ifndef SSRTWSTORAGE_TYPE_RTW_STORAGE_H
#define SSRTWSTORAGE_TYPE_RTW_STORAGE_H
/*
 * Enumeration of RTW storage class
 */
typedef enum {
    SS_RTW_STORAGE_INVALID = -1,
    SS_RTW_STORAGE_AUTO,
    SS_RTW_STORAGE_EXPORTED_GLOBAL,
    SS_RTW_STORAGE_IMPORTED_EXTERN,
    SS_RTW_STORAGE_IMPORTED_EXTERN_POINTER,
    SS_RTW_STORAGE_CUSTOM,
    SS_RTW_STORAGE_SIMULINK_GLOBAL,
    SS_RTW_STORAGE_MODEL_DEFAULT,
    SS_RTW_STORAGE_NUM_CLASSES
} ssRTWStorageType;

#endif /*SSRTWSTORAGE_TYPE_RTW_STORAGE_H*/

/* LocalWords:  SSRTWSTORAGE
 */