// The Wasmer C/C++ header file compatible with the [`wasm-c-api`]
// standard API, as `wasm.h` (included here).
//
// This file is automatically generated by `lib/c-api/build.rs` of the
// [`wasmer-c-api`] Rust crate.
//
// # Stability
//
// The [`wasm-c-api`] standard API is a _living_ standard. There is no
// commitment for stability yet. We (Wasmer) will try our best to keep
// backward compatibility as much as possible. Nonetheless, some
// necessary API aren't yet standardized, and as such, we provide a
// custom API, e.g. `wasi_*` types and functions.
//
// The documentation makes it clear whether a function is unstable.
// 
// When a type or a function will be deprecated, it will be marked as
// such with the appropriated compiler warning, and will be removed at
// the next release round.
//
// # Documentation
//
// At the time of writing, the [`wasm-c-api`] standard has no
// documentation. This file also does not include inline
// documentation. However, we have made (and we continue to make) an
// important effort to document everything. [See the documentation
// online][documentation]. Please refer to this page for the real
// canonical documentation. It also contains numerous examples.
//
// To generate the documentation locally, run `cargo doc --open` from
// within the [`wasmer-c-api`] Rust crate.
//
// [`wasm-c-api`]: https://github.com/WebAssembly/wasm-c-api
// [`wasmer-c-api`]: https://github.com/wasmerio/wasmer/tree/master/lib/c-api
// [documentation]: https://wasmerio.github.io/wasmer/crates/wasmer_c_api/

#if !defined(WASMER_H_PRELUDE)

#define WASMER_H_PRELUDE

// Define the `ARCH_X86_X64` constant.
#if defined(MSVC) && defined(_M_AMD64)
#  define ARCH_X86_64
#elif (defined(GCC) || defined(__GNUC__) || defined(__clang__)) && defined(__x86_64__)
#  define ARCH_X86_64
#endif

// Compatibility with non-Clang compilers.
#if !defined(__has_attribute)
#  define __has_attribute(x) 0
#endif

// Compatibility with non-Clang compilers.
#if !defined(__has_declspec_attribute)
#  define __has_declspec_attribute(x) 0
#endif

// Define the `DEPRECATED` macro.
#if defined(GCC) || defined(__GNUC__) || __has_attribute(deprecated)
#  define DEPRECATED(message) __attribute__((deprecated(message)))
#elif defined(MSVC) || __has_declspec_attribute(deprecated)
#  define DEPRECATED(message) __declspec(deprecated(message))
#endif

// The `universal` feature has been enabled for this build.
#define WASMER_UNIVERSAL_ENABLED

// The `compiler` feature has been enabled for this build.
#define WASMER_COMPILER_ENABLED

// The `wasi` feature has been enabled for this build.
#define WASMER_WASI_ENABLED

// The `middlewares` feature has been enabled for this build.
#define WASMER_MIDDLEWARES_ENABLED

// This file corresponds to the following Wasmer version.
#define WASMER_VERSION "2.0.0-rc1"
#define WASMER_VERSION_MAJOR 2
#define WASMER_VERSION_MINOR 0
#define WASMER_VERSION_PATCH 0
#define WASMER_VERSION_PRE "rc1"

#endif // WASMER_H_PRELUDE


//
// OK, here we go. The code below is automatically generated.
//


#ifndef WASMER_H
#define WASMER_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "wasm.h"

#if defined(WASMER_WASI_ENABLED)
typedef enum wasi_version_t {
#if defined(WASMER_WASI_ENABLED)
  INVALID_VERSION = -1,
#endif
#if defined(WASMER_WASI_ENABLED)
  LATEST = 0,
#endif
#if defined(WASMER_WASI_ENABLED)
  SNAPSHOT0 = 1,
#endif
#if defined(WASMER_WASI_ENABLED)
  SNAPSHOT1 = 2,
#endif
} wasi_version_t;
#endif

#if defined(WASMER_COMPILER_ENABLED)
typedef enum wasmer_compiler_t {
  CRANELIFT = 0,
  LLVM = 1,
  SINGLEPASS = 2,
} wasmer_compiler_t;
#endif

typedef enum wasmer_engine_t {
  UNIVERSAL = 0,
  DYLIB = 1,
  STATICLIB = 2,
} wasmer_engine_t;

typedef enum wasmer_parser_operator_t {
  Unreachable,
  Nop,
  Block,
  Loop,
  If,
  Else,
  Try,
  Catch,
  CatchAll,
  Delegate,
  Throw,
  Rethrow,
  Unwind,
  End,
  Br,
  BrIf,
  BrTable,
  Return,
  Call,
  CallIndirect,
  ReturnCall,
  ReturnCallIndirect,
  Drop,
  Select,
  TypedSelect,
  LocalGet,
  LocalSet,
  LocalTee,
  GlobalGet,
  GlobalSet,
  I32Load,
  I64Load,
  F32Load,
  F64Load,
  I32Load8S,
  I32Load8U,
  I32Load16S,
  I32Load16U,
  I64Load8S,
  I64Load8U,
  I64Load16S,
  I64Load16U,
  I64Load32S,
  I64Load32U,
  I32Store,
  I64Store,
  F32Store,
  F64Store,
  I32Store8,
  I32Store16,
  I64Store8,
  I64Store16,
  I64Store32,
  MemorySize,
  MemoryGrow,
  I32Const,
  I64Const,
  F32Const,
  F64Const,
  RefNull,
  RefIsNull,
  RefFunc,
  I32Eqz,
  I32Eq,
  I32Ne,
  I32LtS,
  I32LtU,
  I32GtS,
  I32GtU,
  I32LeS,
  I32LeU,
  I32GeS,
  I32GeU,
  I64Eqz,
  I64Eq,
  I64Ne,
  I64LtS,
  I64LtU,
  I64GtS,
  I64GtU,
  I64LeS,
  I64LeU,
  I64GeS,
  I64GeU,
  F32Eq,
  F32Ne,
  F32Lt,
  F32Gt,
  F32Le,
  F32Ge,
  F64Eq,
  F64Ne,
  F64Lt,
  F64Gt,
  F64Le,
  F64Ge,
  I32Clz,
  I32Ctz,
  I32Popcnt,
  I32Add,
  I32Sub,
  I32Mul,
  I32DivS,
  I32DivU,
  I32RemS,
  I32RemU,
  I32And,
  I32Or,
  I32Xor,
  I32Shl,
  I32ShrS,
  I32ShrU,
  I32Rotl,
  I32Rotr,
  I64Clz,
  I64Ctz,
  I64Popcnt,
  I64Add,
  I64Sub,
  I64Mul,
  I64DivS,
  I64DivU,
  I64RemS,
  I64RemU,
  I64And,
  I64Or,
  I64Xor,
  I64Shl,
  I64ShrS,
  I64ShrU,
  I64Rotl,
  I64Rotr,
  F32Abs,
  F32Neg,
  F32Ceil,
  F32Floor,
  F32Trunc,
  F32Nearest,
  F32Sqrt,
  F32Add,
  F32Sub,
  F32Mul,
  F32Div,
  F32Min,
  F32Max,
  F32Copysign,
  F64Abs,
  F64Neg,
  F64Ceil,
  F64Floor,
  F64Trunc,
  F64Nearest,
  F64Sqrt,
  F64Add,
  F64Sub,
  F64Mul,
  F64Div,
  F64Min,
  F64Max,
  F64Copysign,
  I32WrapI64,
  I32TruncF32S,
  I32TruncF32U,
  I32TruncF64S,
  I32TruncF64U,
  I64ExtendI32S,
  I64ExtendI32U,
  I64TruncF32S,
  I64TruncF32U,
  I64TruncF64S,
  I64TruncF64U,
  F32ConvertI32S,
  F32ConvertI32U,
  F32ConvertI64S,
  F32ConvertI64U,
  F32DemoteF64,
  F64ConvertI32S,
  F64ConvertI32U,
  F64ConvertI64S,
  F64ConvertI64U,
  F64PromoteF32,
  I32ReinterpretF32,
  I64ReinterpretF64,
  F32ReinterpretI32,
  F64ReinterpretI64,
  I32Extend8S,
  I32Extend16S,
  I64Extend8S,
  I64Extend16S,
  I64Extend32S,
  I32TruncSatF32S,
  I32TruncSatF32U,
  I32TruncSatF64S,
  I32TruncSatF64U,
  I64TruncSatF32S,
  I64TruncSatF32U,
  I64TruncSatF64S,
  I64TruncSatF64U,
  MemoryInit,
  DataDrop,
  MemoryCopy,
  MemoryFill,
  TableInit,
  ElemDrop,
  TableCopy,
  TableFill,
  TableGet,
  TableSet,
  TableGrow,
  TableSize,
  MemoryAtomicNotify,
  MemoryAtomicWait32,
  MemoryAtomicWait64,
  AtomicFence,
  I32AtomicLoad,
  I64AtomicLoad,
  I32AtomicLoad8U,
  I32AtomicLoad16U,
  I64AtomicLoad8U,
  I64AtomicLoad16U,
  I64AtomicLoad32U,
  I32AtomicStore,
  I64AtomicStore,
  I32AtomicStore8,
  I32AtomicStore16,
  I64AtomicStore8,
  I64AtomicStore16,
  I64AtomicStore32,
  I32AtomicRmwAdd,
  I64AtomicRmwAdd,
  I32AtomicRmw8AddU,
  I32AtomicRmw16AddU,
  I64AtomicRmw8AddU,
  I64AtomicRmw16AddU,
  I64AtomicRmw32AddU,
  I32AtomicRmwSub,
  I64AtomicRmwSub,
  I32AtomicRmw8SubU,
  I32AtomicRmw16SubU,
  I64AtomicRmw8SubU,
  I64AtomicRmw16SubU,
  I64AtomicRmw32SubU,
  I32AtomicRmwAnd,
  I64AtomicRmwAnd,
  I32AtomicRmw8AndU,
  I32AtomicRmw16AndU,
  I64AtomicRmw8AndU,
  I64AtomicRmw16AndU,
  I64AtomicRmw32AndU,
  I32AtomicRmwOr,
  I64AtomicRmwOr,
  I32AtomicRmw8OrU,
  I32AtomicRmw16OrU,
  I64AtomicRmw8OrU,
  I64AtomicRmw16OrU,
  I64AtomicRmw32OrU,
  I32AtomicRmwXor,
  I64AtomicRmwXor,
  I32AtomicRmw8XorU,
  I32AtomicRmw16XorU,
  I64AtomicRmw8XorU,
  I64AtomicRmw16XorU,
  I64AtomicRmw32XorU,
  I32AtomicRmwXchg,
  I64AtomicRmwXchg,
  I32AtomicRmw8XchgU,
  I32AtomicRmw16XchgU,
  I64AtomicRmw8XchgU,
  I64AtomicRmw16XchgU,
  I64AtomicRmw32XchgU,
  I32AtomicRmwCmpxchg,
  I64AtomicRmwCmpxchg,
  I32AtomicRmw8CmpxchgU,
  I32AtomicRmw16CmpxchgU,
  I64AtomicRmw8CmpxchgU,
  I64AtomicRmw16CmpxchgU,
  I64AtomicRmw32CmpxchgU,
  V128Load,
  V128Store,
  V128Const,
  I8x16Splat,
  I8x16ExtractLaneS,
  I8x16ExtractLaneU,
  I8x16ReplaceLane,
  I16x8Splat,
  I16x8ExtractLaneS,
  I16x8ExtractLaneU,
  I16x8ReplaceLane,
  I32x4Splat,
  I32x4ExtractLane,
  I32x4ReplaceLane,
  I64x2Splat,
  I64x2ExtractLane,
  I64x2ReplaceLane,
  F32x4Splat,
  F32x4ExtractLane,
  F32x4ReplaceLane,
  F64x2Splat,
  F64x2ExtractLane,
  F64x2ReplaceLane,
  I8x16Eq,
  I8x16Ne,
  I8x16LtS,
  I8x16LtU,
  I8x16GtS,
  I8x16GtU,
  I8x16LeS,
  I8x16LeU,
  I8x16GeS,
  I8x16GeU,
  I16x8Eq,
  I16x8Ne,
  I16x8LtS,
  I16x8LtU,
  I16x8GtS,
  I16x8GtU,
  I16x8LeS,
  I16x8LeU,
  I16x8GeS,
  I16x8GeU,
  I32x4Eq,
  I32x4Ne,
  I32x4LtS,
  I32x4LtU,
  I32x4GtS,
  I32x4GtU,
  I32x4LeS,
  I32x4LeU,
  I32x4GeS,
  I32x4GeU,
  I64x2Eq,
  I64x2Ne,
  I64x2LtS,
  I64x2GtS,
  I64x2LeS,
  I64x2GeS,
  F32x4Eq,
  F32x4Ne,
  F32x4Lt,
  F32x4Gt,
  F32x4Le,
  F32x4Ge,
  F64x2Eq,
  F64x2Ne,
  F64x2Lt,
  F64x2Gt,
  F64x2Le,
  F64x2Ge,
  V128Not,
  V128And,
  V128AndNot,
  V128Or,
  V128Xor,
  V128Bitselect,
  V128AnyTrue,
  I8x16Abs,
  I8x16Neg,
  I8x16AllTrue,
  I8x16Bitmask,
  I8x16Shl,
  I8x16ShrS,
  I8x16ShrU,
  I8x16Add,
  I8x16AddSatS,
  I8x16AddSatU,
  I8x16Sub,
  I8x16SubSatS,
  I8x16SubSatU,
  I8x16MinS,
  I8x16MinU,
  I8x16MaxS,
  I8x16MaxU,
  I8x16Popcnt,
  I16x8Abs,
  I16x8Neg,
  I16x8AllTrue,
  I16x8Bitmask,
  I16x8Shl,
  I16x8ShrS,
  I16x8ShrU,
  I16x8Add,
  I16x8AddSatS,
  I16x8AddSatU,
  I16x8Sub,
  I16x8SubSatS,
  I16x8SubSatU,
  I16x8Mul,
  I16x8MinS,
  I16x8MinU,
  I16x8MaxS,
  I16x8MaxU,
  I16x8ExtAddPairwiseI8x16S,
  I16x8ExtAddPairwiseI8x16U,
  I32x4Abs,
  I32x4Neg,
  I32x4AllTrue,
  I32x4Bitmask,
  I32x4Shl,
  I32x4ShrS,
  I32x4ShrU,
  I32x4Add,
  I32x4Sub,
  I32x4Mul,
  I32x4MinS,
  I32x4MinU,
  I32x4MaxS,
  I32x4MaxU,
  I32x4DotI16x8S,
  I32x4ExtAddPairwiseI16x8S,
  I32x4ExtAddPairwiseI16x8U,
  I64x2Abs,
  I64x2Neg,
  I64x2AllTrue,
  I64x2Bitmask,
  I64x2Shl,
  I64x2ShrS,
  I64x2ShrU,
  I64x2Add,
  I64x2Sub,
  I64x2Mul,
  F32x4Ceil,
  F32x4Floor,
  F32x4Trunc,
  F32x4Nearest,
  F64x2Ceil,
  F64x2Floor,
  F64x2Trunc,
  F64x2Nearest,
  F32x4Abs,
  F32x4Neg,
  F32x4Sqrt,
  F32x4Add,
  F32x4Sub,
  F32x4Mul,
  F32x4Div,
  F32x4Min,
  F32x4Max,
  F32x4PMin,
  F32x4PMax,
  F64x2Abs,
  F64x2Neg,
  F64x2Sqrt,
  F64x2Add,
  F64x2Sub,
  F64x2Mul,
  F64x2Div,
  F64x2Min,
  F64x2Max,
  F64x2PMin,
  F64x2PMax,
  I32x4TruncSatF32x4S,
  I32x4TruncSatF32x4U,
  F32x4ConvertI32x4S,
  F32x4ConvertI32x4U,
  I8x16Swizzle,
  I8x16Shuffle,
  V128Load8Splat,
  V128Load16Splat,
  V128Load32Splat,
  V128Load32Zero,
  V128Load64Splat,
  V128Load64Zero,
  I8x16NarrowI16x8S,
  I8x16NarrowI16x8U,
  I16x8NarrowI32x4S,
  I16x8NarrowI32x4U,
  I16x8ExtendLowI8x16S,
  I16x8ExtendHighI8x16S,
  I16x8ExtendLowI8x16U,
  I16x8ExtendHighI8x16U,
  I32x4ExtendLowI16x8S,
  I32x4ExtendHighI16x8S,
  I32x4ExtendLowI16x8U,
  I32x4ExtendHighI16x8U,
  I64x2ExtendLowI32x4S,
  I64x2ExtendHighI32x4S,
  I64x2ExtendLowI32x4U,
  I64x2ExtendHighI32x4U,
  I16x8ExtMulLowI8x16S,
  I16x8ExtMulHighI8x16S,
  I16x8ExtMulLowI8x16U,
  I16x8ExtMulHighI8x16U,
  I32x4ExtMulLowI16x8S,
  I32x4ExtMulHighI16x8S,
  I32x4ExtMulLowI16x8U,
  I32x4ExtMulHighI16x8U,
  I64x2ExtMulLowI32x4S,
  I64x2ExtMulHighI32x4S,
  I64x2ExtMulLowI32x4U,
  I64x2ExtMulHighI32x4U,
  V128Load8x8S,
  V128Load8x8U,
  V128Load16x4S,
  V128Load16x4U,
  V128Load32x2S,
  V128Load32x2U,
  V128Load8Lane,
  V128Load16Lane,
  V128Load32Lane,
  V128Load64Lane,
  V128Store8Lane,
  V128Store16Lane,
  V128Store32Lane,
  V128Store64Lane,
  I8x16RoundingAverageU,
  I16x8RoundingAverageU,
  I16x8Q15MulrSatS,
  F32x4DemoteF64x2Zero,
  F64x2PromoteLowF32x4,
  F64x2ConvertLowI32x4S,
  F64x2ConvertLowI32x4U,
  I32x4TruncSatF64x2SZero,
  I32x4TruncSatF64x2UZero,
} wasmer_parser_operator_t;

#if defined(WASMER_WASI_ENABLED)
typedef struct wasi_config_t wasi_config_t;
#endif

#if defined(WASMER_WASI_ENABLED)
typedef struct wasi_env_t wasi_env_t;
#endif

typedef struct wasmer_cpu_features_t wasmer_cpu_features_t;

typedef struct wasmer_features_t wasmer_features_t;

typedef struct wasmer_metering_t wasmer_metering_t;

typedef struct wasmer_middleware_t wasmer_middleware_t;

#if defined(WASMER_WASI_ENABLED)
typedef struct wasmer_named_extern_t wasmer_named_extern_t;
#endif

typedef struct wasmer_target_t wasmer_target_t;

typedef struct wasmer_triple_t wasmer_triple_t;

#if defined(WASMER_WASI_ENABLED)
typedef struct wasmer_named_extern_vec_t {
  uintptr_t size;
  struct wasmer_named_extern_t **data;
} wasmer_named_extern_vec_t;
#endif

typedef uint64_t (*wasmer_metering_cost_function_t)(enum wasmer_parser_operator_t wasm_operator);

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if defined(WASMER_WASI_ENABLED)
void wasi_config_arg(struct wasi_config_t *config, const char *arg);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_capture_stderr(struct wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_capture_stdout(struct wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_env(struct wasi_config_t *config, const char *key, const char *value);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_inherit_stderr(struct wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_inherit_stdin(struct wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_inherit_stdout(struct wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
bool wasi_config_mapdir(struct wasi_config_t *config, const char *alias, const char *dir);
#endif

#if defined(WASMER_WASI_ENABLED)
struct wasi_config_t *wasi_config_new(const char *program_name);
#endif

#if defined(WASMER_WASI_ENABLED)
bool wasi_config_preopen_dir(struct wasi_config_t *config, const char *dir);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_env_delete(struct wasi_env_t *_state);
#endif

#if defined(WASMER_WASI_ENABLED)
struct wasi_env_t *wasi_env_new(struct wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
intptr_t wasi_env_read_stderr(struct wasi_env_t *env, char *buffer, uintptr_t buffer_len);
#endif

#if defined(WASMER_WASI_ENABLED)
intptr_t wasi_env_read_stdout(struct wasi_env_t *env, char *buffer, uintptr_t buffer_len);
#endif

#if defined(WASMER_WASI_ENABLED)
bool wasi_get_imports(const wasm_store_t *store,
                      const wasm_module_t *module,
                      const struct wasi_env_t *wasi_env,
                      wasm_extern_vec_t *imports);
#endif

#if defined(WASMER_WASI_ENABLED)
wasm_func_t *wasi_get_start_function(wasm_instance_t *instance);
#endif

#if defined(WASMER_WASI_ENABLED)
bool wasi_get_unordered_imports(const wasm_store_t *store,
                                const wasm_module_t *module,
                                const struct wasi_env_t *wasi_env,
                                struct wasmer_named_extern_vec_t *imports);
#endif

#if defined(WASMER_WASI_ENABLED)
enum wasi_version_t wasi_get_wasi_version(const wasm_module_t *module);
#endif

void wasm_config_canonicalize_nans(wasm_config_t *config, bool enable);

void wasm_config_push_middleware(wasm_config_t *config, struct wasmer_middleware_t *middleware);

#if defined(WASMER_COMPILER_ENABLED)
void wasm_config_set_compiler(wasm_config_t *config, enum wasmer_compiler_t compiler);
#endif

void wasm_config_set_engine(wasm_config_t *config, enum wasmer_engine_t engine);

void wasm_config_set_features(wasm_config_t *config, struct wasmer_features_t *features);

void wasm_config_set_target(wasm_config_t *config, struct wasmer_target_t *target);

bool wasmer_cpu_features_add(struct wasmer_cpu_features_t *cpu_features,
                             const wasm_name_t *feature);

void wasmer_cpu_features_delete(struct wasmer_cpu_features_t *_cpu_features);

struct wasmer_cpu_features_t *wasmer_cpu_features_new(void);

bool wasmer_features_bulk_memory(struct wasmer_features_t *features, bool enable);

void wasmer_features_delete(struct wasmer_features_t *_features);

bool wasmer_features_memory64(struct wasmer_features_t *features, bool enable);

bool wasmer_features_module_linking(struct wasmer_features_t *features, bool enable);

bool wasmer_features_multi_memory(struct wasmer_features_t *features, bool enable);

bool wasmer_features_multi_value(struct wasmer_features_t *features, bool enable);

struct wasmer_features_t *wasmer_features_new(void);

bool wasmer_features_reference_types(struct wasmer_features_t *features, bool enable);

bool wasmer_features_simd(struct wasmer_features_t *features, bool enable);

bool wasmer_features_tail_call(struct wasmer_features_t *features, bool enable);

bool wasmer_features_threads(struct wasmer_features_t *features, bool enable);

bool wasmer_is_compiler_available(enum wasmer_compiler_t compiler);

bool wasmer_is_engine_available(enum wasmer_engine_t engine);

bool wasmer_is_headless(void);

int wasmer_last_error_length(void);

int wasmer_last_error_message(char *buffer, int length);

struct wasmer_middleware_t *wasmer_metering_as_middleware(struct wasmer_metering_t *metering);

void wasmer_metering_delete(struct wasmer_metering_t *_metering);

uint64_t wasmer_metering_get_remaining_points(const wasm_instance_t *instance);

struct wasmer_metering_t *wasmer_metering_new(uint64_t initial_limit,
                                              wasmer_metering_cost_function_t cost_function);

bool wasmer_metering_points_are_exhausted(const wasm_instance_t *instance);

void wasmer_metering_set_remaining_points(const wasm_instance_t *instance, uint64_t new_limit);

void wasmer_module_name(const wasm_module_t *module, wasm_name_t *out);

bool wasmer_module_set_name(wasm_module_t *module, const wasm_name_t *name);

#if defined(WASMER_WASI_ENABLED)
const wasm_name_t *wasmer_named_extern_module(const struct wasmer_named_extern_t *named_extern);
#endif

#if defined(WASMER_WASI_ENABLED)
const wasm_name_t *wasmer_named_extern_name(const struct wasmer_named_extern_t *named_extern);
#endif

#if defined(WASMER_WASI_ENABLED)
const wasm_extern_t *wasmer_named_extern_unwrap(const struct wasmer_named_extern_t *named_extern);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasmer_named_extern_vec_copy(struct wasmer_named_extern_vec_t *out_ptr,
                                  const struct wasmer_named_extern_vec_t *in_ptr);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasmer_named_extern_vec_delete(struct wasmer_named_extern_vec_t *ptr);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasmer_named_extern_vec_new(struct wasmer_named_extern_vec_t *out,
                                 uintptr_t length,
                                 struct wasmer_named_extern_t *const *init);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasmer_named_extern_vec_new_empty(struct wasmer_named_extern_vec_t *out);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasmer_named_extern_vec_new_uninitialized(struct wasmer_named_extern_vec_t *out,
                                               uintptr_t length);
#endif

void wasmer_target_delete(struct wasmer_target_t *_target);

struct wasmer_target_t *wasmer_target_new(struct wasmer_triple_t *triple,
                                          struct wasmer_cpu_features_t *cpu_features);

void wasmer_triple_delete(struct wasmer_triple_t *_triple);

struct wasmer_triple_t *wasmer_triple_new(const wasm_name_t *triple);

struct wasmer_triple_t *wasmer_triple_new_from_host(void);

const char *wasmer_version(void);

uint8_t wasmer_version_major(void);

uint8_t wasmer_version_minor(void);

uint8_t wasmer_version_patch(void);

const char *wasmer_version_pre(void);

void wat2wasm(const wasm_byte_vec_t *wat, wasm_byte_vec_t *out);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* WASMER_H */
