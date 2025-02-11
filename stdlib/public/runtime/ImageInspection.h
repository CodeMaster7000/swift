//===--- ImageInspection.h - Image inspection routines ----------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2017 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
///
/// \file
///
/// This file includes routines that extract metadata from executable and
/// dynamic library image files generated by the Swift compiler. The concrete
/// implementations vary greatly by platform.
///
//===----------------------------------------------------------------------===//

#ifndef SWIFT_RUNTIME_IMAGEINSPECTION_H
#define SWIFT_RUNTIME_IMAGEINSPECTION_H

#include "swift/Runtime/Config.h"

#include <cstdint>
#include <cstddef>
#include <functional>
#include <memory>
#include <type_traits>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#endif

#include "SymbolInfo.h"

namespace swift {

/// Load the metadata from the image necessary to find protocols by name.
void initializeProtocolLookup();

/// Load the metadata from the image necessary to find a type's
/// protocol conformance.
void initializeProtocolConformanceLookup();

/// Load the metadata from the image necessary to find a type by name.
void initializeTypeMetadataRecordLookup();

/// Load the metadata from the image necessary to perform dynamic replacements.
void initializeDynamicReplacementLookup();

/// Load the metadata from the image necessary to find functions by name.
void initializeAccessibleFunctionsLookup();

/// Load the metadata from the image necessary to find runtime metadata.
void initializeRuntimeAttributesLookup();

// Callbacks to register metadata from an image to the runtime.
void addImageProtocolsBlockCallback(const void *baseAddress,
                                    const void *start, uintptr_t size);
void addImageProtocolsBlockCallbackUnsafe(const void *baseAddress,
                                          const void *start, uintptr_t size);
void addImageProtocolConformanceBlockCallback(const void *baseAddress,
                                              const void *start,
                                              uintptr_t size);
void addImageProtocolConformanceBlockCallbackUnsafe(const void *baseAddress,
                                                    const void *start,
                                                    uintptr_t size);
void addImageTypeMetadataRecordBlockCallback(const void *baseAddress,
                                             const void *start,
                                             uintptr_t size);
void addImageTypeMetadataRecordBlockCallbackUnsafe(const void *baseAddress,
                                                   const void *start,
                                                   uintptr_t size);
void addImageDynamicReplacementBlockCallback(const void *baseAddress,
                                             const void *start, uintptr_t size,
                                             const void *start2,
                                             uintptr_t size2);
void addImageAccessibleFunctionsBlockCallback(const void *baseAddress,
                                              const void *start,
                                              uintptr_t size);
void addImageAccessibleFunctionsBlockCallbackUnsafe(const void *baseAddress,
                                                    const void *start,
                                                    uintptr_t size);
void addImageRuntimeAttributesBlockCallback(const void *baseAddress,
                                            const void *start,
                                            uintptr_t size);
void addImageRuntimeAttributesBlockCallbackUnsafe(const void *baseAddress,
                                                  const void *start,
                                                  uintptr_t size);

} // end namespace swift

#endif
