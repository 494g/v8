// Copyright 2022 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/wasm/wasm-opcodes-inl.h"
#include "test/unittests/test-utils.h"

namespace v8 {
namespace internal {
namespace wasm {

class WasmOpcodeTest : public TestWithZone {
 public:
  void CheckName(WasmOpcode opcode, const char* expected) {
    EXPECT_STREQ(expected, WasmOpcodes::OpcodeName(opcode));
  }

  void CheckSimdName(uint32_t opcode_after_prefix, const char* expected) {
    uint32_t raw = kSimdPrefix << (opcode_after_prefix <= 0xFF ? 8 : 12);
    raw |= opcode_after_prefix;
    WasmOpcode opcode = static_cast<WasmOpcode>(raw);
    CheckName(opcode, expected);
  }
};

TEST_F(WasmOpcodeTest, SimdNames) {
  // Reference:
  // https://webassembly.github.io/spec/core/binary/instructions.html#vector-instructions
  CheckSimdName(0, "v128.load");
  CheckSimdName(1, "v128.load8x8_s");
  CheckSimdName(2, "v128.load8x8_u");
  CheckSimdName(3, "v128.load16x4_s");
  CheckSimdName(4, "v128.load16x4_u");
  CheckSimdName(5, "v128.load32x2_s");
  CheckSimdName(6, "v128.load32x2_u");
  CheckSimdName(7, "v128.load8_splat");
  CheckSimdName(8, "v128.load16_splat");
  CheckSimdName(9, "v128.load32_splat");
  CheckSimdName(10, "v128.load64_splat");
  CheckSimdName(92, "v128.load32_zero");
  CheckSimdName(93, "v128.load64_zero");
  CheckSimdName(11, "v128.store");
  CheckSimdName(84, "v128.load8_lane");
  CheckSimdName(85, "v128.load16_lane");
  CheckSimdName(86, "v128.load32_lane");
  CheckSimdName(87, "v128.load64_lane");
  CheckSimdName(88, "v128.store8_lane");
  CheckSimdName(89, "v128.store16_lane");
  CheckSimdName(90, "v128.store32_lane");
  CheckSimdName(91, "v128.store64_lane");
  CheckSimdName(12, "v128.const");
  CheckSimdName(13, "i8x16.shuffle");
  CheckSimdName(21, "i8x16.extract_lane_s");
  CheckSimdName(22, "i8x16.extract_lane_u");
  CheckSimdName(23, "i8x16.replace_lane");
  CheckSimdName(24, "i16x8.extract_lane_s");
  CheckSimdName(25, "i16x8.extract_lane_u");
  CheckSimdName(26, "i16x8.replace_lane");
  CheckSimdName(27, "i32x4.extract_lane");
  CheckSimdName(28, "i32x4.replace_lane");
  CheckSimdName(29, "i64x2.extract_lane");
  CheckSimdName(30, "i64x2.replace_lane");
  CheckSimdName(31, "f32x4.extract_lane");
  CheckSimdName(32, "f32x4.replace_lane");
  CheckSimdName(33, "f64x2.extract_lane");
  CheckSimdName(34, "f64x2.replace_lane");
  CheckSimdName(14, "i8x16.swizzle");
  CheckSimdName(15, "i8x16.splat");
  CheckSimdName(16, "i16x8.splat");
  CheckSimdName(17, "i32x4.splat");
  CheckSimdName(18, "i64x2.splat");
  CheckSimdName(19, "f32x4.splat");
  CheckSimdName(20, "f64x2.splat");
  CheckSimdName(35, "i8x16.eq");
  CheckSimdName(36, "i8x16.ne");
  CheckSimdName(37, "i8x16.lt_s");
  CheckSimdName(38, "i8x16.lt_u");
  CheckSimdName(39, "i8x16.gt_s");
  CheckSimdName(40, "i8x16.gt_u");
  CheckSimdName(41, "i8x16.le_s");
  CheckSimdName(42, "i8x16.le_u");
  CheckSimdName(43, "i8x16.ge_s");
  CheckSimdName(44, "i8x16.ge_u");
  CheckSimdName(45, "i16x8.eq");
  CheckSimdName(46, "i16x8.ne");
  CheckSimdName(47, "i16x8.lt_s");
  CheckSimdName(48, "i16x8.lt_u");
  CheckSimdName(49, "i16x8.gt_s");
  CheckSimdName(50, "i16x8.gt_u");
  CheckSimdName(51, "i16x8.le_s");
  CheckSimdName(52, "i16x8.le_u");
  CheckSimdName(53, "i16x8.ge_s");
  CheckSimdName(54, "i16x8.ge_u");
  CheckSimdName(55, "i32x4.eq");
  CheckSimdName(56, "i32x4.ne");
  CheckSimdName(57, "i32x4.lt_s");
  CheckSimdName(58, "i32x4.lt_u");
  CheckSimdName(59, "i32x4.gt_s");
  CheckSimdName(60, "i32x4.gt_u");
  CheckSimdName(61, "i32x4.le_s");
  CheckSimdName(62, "i32x4.le_u");
  CheckSimdName(63, "i32x4.ge_s");
  CheckSimdName(64, "i32x4.ge_u");
  CheckSimdName(214, "i64x2.eq");
  CheckSimdName(215, "i64x2.ne");
  CheckSimdName(216, "i64x2.lt_s");
  CheckSimdName(217, "i64x2.gt_s");
  CheckSimdName(218, "i64x2.le_s");
  CheckSimdName(219, "i64x2.ge_s");
  CheckSimdName(65, "f32x4.eq");
  CheckSimdName(66, "f32x4.ne");
  CheckSimdName(67, "f32x4.lt");
  CheckSimdName(68, "f32x4.gt");
  CheckSimdName(69, "f32x4.le");
  CheckSimdName(70, "f32x4.ge");
  CheckSimdName(71, "f64x2.eq");
  CheckSimdName(72, "f64x2.ne");
  CheckSimdName(73, "f64x2.lt");
  CheckSimdName(74, "f64x2.gt");
  CheckSimdName(75, "f64x2.le");
  CheckSimdName(76, "f64x2.ge");
  CheckSimdName(77, "v128.not");
  CheckSimdName(78, "v128.and");
  CheckSimdName(79, "v128.andnot");
  CheckSimdName(80, "v128.or");
  CheckSimdName(81, "v128.xor");
  CheckSimdName(82, "v128.bitselect");
  CheckSimdName(83, "v128.any_true");
  CheckSimdName(96, "i8x16.abs");
  CheckSimdName(97, "i8x16.neg");
  CheckSimdName(98, "i8x16.popcnt");
  CheckSimdName(99, "i8x16.all_true");
  CheckSimdName(100, "i8x16.bitmask");
  CheckSimdName(101, "i8x16.narrow_i16x8_s");
  CheckSimdName(102, "i8x16.narrow_i16x8_u");
  CheckSimdName(107, "i8x16.shl");
  CheckSimdName(108, "i8x16.shr_s");
  CheckSimdName(109, "i8x16.shr_u");
  CheckSimdName(110, "i8x16.add");
  CheckSimdName(111, "i8x16.add_sat_s");
  CheckSimdName(112, "i8x16.add_sat_u");
  CheckSimdName(113, "i8x16.sub");
  CheckSimdName(114, "i8x16.sub_sat_s");
  CheckSimdName(115, "i8x16.sub_sat_u");
  CheckSimdName(118, "i8x16.min_s");
  CheckSimdName(119, "i8x16.min_u");
  CheckSimdName(120, "i8x16.max_s");
  CheckSimdName(121, "i8x16.max_u");
  CheckSimdName(123, "i8x16.avgr_u");
  CheckSimdName(124, "i16x8.extadd_pairwise_i8x16_s");
  CheckSimdName(125, "i16x8.extadd_pairwise_i8x16_u");
  CheckSimdName(128, "i16x8.abs");
  CheckSimdName(129, "i16x8.neg");
  CheckSimdName(130, "i16x8.q15mulr_sat_s");
  CheckSimdName(131, "i16x8.all_true");
  CheckSimdName(132, "i16x8.bitmask");
  CheckSimdName(133, "i16x8.narrow_i32x4_s");
  CheckSimdName(134, "i16x8.narrow_i32x4_u");
  CheckSimdName(135, "i16x8.extend_low_i8x16_s");
  CheckSimdName(136, "i16x8.extend_high_i8x16_s");
  CheckSimdName(137, "i16x8.extend_low_i8x16_u");
  CheckSimdName(138, "i16x8.extend_high_i8x16_u");
  CheckSimdName(139, "i16x8.shl");
  CheckSimdName(140, "i16x8.shr_s");
  CheckSimdName(141, "i16x8.shr_u");
  CheckSimdName(142, "i16x8.add");
  CheckSimdName(143, "i16x8.add_sat_s");
  CheckSimdName(144, "i16x8.add_sat_u");
  CheckSimdName(145, "i16x8.sub");
  CheckSimdName(146, "i16x8.sub_sat_s");
  CheckSimdName(147, "i16x8.sub_sat_u");
  CheckSimdName(149, "i16x8.mul");
  CheckSimdName(150, "i16x8.min_s");
  CheckSimdName(151, "i16x8.min_u");
  CheckSimdName(152, "i16x8.max_s");
  CheckSimdName(153, "i16x8.max_u");
  CheckSimdName(155, "i16x8.avgr_u");
  CheckSimdName(156, "i16x8.extmul_low_i8x16_s");
  CheckSimdName(157, "i16x8.extmul_high_i8x16_s");
  CheckSimdName(158, "i16x8.extmul_low_i8x16_u");
  CheckSimdName(159, "i16x8.extmul_high_i8x16_u");
  CheckSimdName(126, "i32x4.extadd_pairwise_i16x8_s");
  CheckSimdName(127, "i32x4.extadd_pairwise_i16x8_u");
  CheckSimdName(160, "i32x4.abs");
  CheckSimdName(161, "i32x4.neg");
  CheckSimdName(163, "i32x4.all_true");
  CheckSimdName(164, "i32x4.bitmask");
  CheckSimdName(167, "i32x4.extend_low_i16x8_s");
  CheckSimdName(168, "i32x4.extend_high_i16x8_s");
  CheckSimdName(169, "i32x4.extend_low_i16x8_u");
  CheckSimdName(170, "i32x4.extend_high_i16x8_u");
  CheckSimdName(171, "i32x4.shl");
  CheckSimdName(172, "i32x4.shr_s");
  CheckSimdName(173, "i32x4.shr_u");
  CheckSimdName(174, "i32x4.add");
  CheckSimdName(177, "i32x4.sub");
  CheckSimdName(181, "i32x4.mul");
  CheckSimdName(182, "i32x4.min_s");
  CheckSimdName(183, "i32x4.min_u");
  CheckSimdName(184, "i32x4.max_s");
  CheckSimdName(185, "i32x4.max_u");
  CheckSimdName(186, "i32x4.dot_i16x8_s");
  CheckSimdName(188, "i32x4.extmul_low_i16x8_s");
  CheckSimdName(189, "i32x4.extmul_high_i16x8_s");
  CheckSimdName(190, "i32x4.extmul_low_i16x8_u");
  CheckSimdName(191, "i32x4.extmul_high_i16x8_u");
  CheckSimdName(192, "i64x2.abs");
  CheckSimdName(193, "i64x2.neg");
  CheckSimdName(195, "i64x2.all_true");
  CheckSimdName(196, "i64x2.bitmask");
  CheckSimdName(199, "i64x2.extend_low_i32x4_s");
  CheckSimdName(200, "i64x2.extend_high_i32x4_s");
  CheckSimdName(201, "i64x2.extend_low_i32x4_u");
  CheckSimdName(202, "i64x2.extend_high_i32x4_u");
  CheckSimdName(203, "i64x2.shl");
  CheckSimdName(204, "i64x2.shr_s");
  CheckSimdName(205, "i64x2.shr_u");
  CheckSimdName(206, "i64x2.add");
  CheckSimdName(209, "i64x2.sub");
  CheckSimdName(213, "i64x2.mul");
  CheckSimdName(220, "i64x2.extmul_low_i32x4_s");
  CheckSimdName(221, "i64x2.extmul_high_i32x4_s");
  CheckSimdName(222, "i64x2.extmul_low_i32x4_u");
  CheckSimdName(223, "i64x2.extmul_high_i32x4_u");
  CheckSimdName(103, "f32x4.ceil");
  CheckSimdName(104, "f32x4.floor");
  CheckSimdName(105, "f32x4.trunc");
  CheckSimdName(106, "f32x4.nearest");
  CheckSimdName(224, "f32x4.abs");
  CheckSimdName(225, "f32x4.neg");
  CheckSimdName(227, "f32x4.sqrt");
  CheckSimdName(228, "f32x4.add");
  CheckSimdName(229, "f32x4.sub");
  CheckSimdName(230, "f32x4.mul");
  CheckSimdName(231, "f32x4.div");
  CheckSimdName(232, "f32x4.min");
  CheckSimdName(233, "f32x4.max");
  CheckSimdName(234, "f32x4.pmin");
  CheckSimdName(235, "f32x4.pmax");
  CheckSimdName(116, "f64x2.ceil");
  CheckSimdName(117, "f64x2.floor");
  CheckSimdName(122, "f64x2.trunc");
  CheckSimdName(148, "f64x2.nearest");
  CheckSimdName(236, "f64x2.abs");
  CheckSimdName(237, "f64x2.neg");
  CheckSimdName(239, "f64x2.sqrt");
  CheckSimdName(240, "f64x2.add");
  CheckSimdName(241, "f64x2.sub");
  CheckSimdName(242, "f64x2.mul");
  CheckSimdName(243, "f64x2.div");
  CheckSimdName(244, "f64x2.min");
  CheckSimdName(245, "f64x2.max");
  CheckSimdName(246, "f64x2.pmin");
  CheckSimdName(247, "f64x2.pmax");
  CheckSimdName(248, "i32x4.trunc_sat_f32x4_s");
  CheckSimdName(249, "i32x4.trunc_sat_f32x4_u");
  CheckSimdName(250, "f32x4.convert_i32x4_s");
  CheckSimdName(251, "f32x4.convert_i32x4_u");
  CheckSimdName(252, "i32x4.trunc_sat_f64x2_s_zero");
  CheckSimdName(253, "i32x4.trunc_sat_f64x2_u_zero");
  CheckSimdName(254, "f64x2.convert_low_i32x4_s");
  CheckSimdName(255, "f64x2.convert_low_i32x4_u");
  CheckSimdName(94, "f32x4.demote_f64x2_zero");
  CheckSimdName(95, "f64x2.promote_low_f32x4");
}

TEST_F(WasmOpcodeTest, AtomicNames) {
  // Reference:
  // https://webassembly.github.io/threads/core/text/instructions.html#atomic-memory-instructions
  CheckName(kExprAtomicNotify, "memory.atomic.notify");
  CheckName(kExprI32AtomicWait, "memory.atomic.wait32");
  CheckName(kExprI64AtomicWait, "memory.atomic.wait64");
  CheckName(kExprI32AtomicLoad, "i32.atomic.load");
  CheckName(kExprI64AtomicLoad, "i64.atomic.load");
  CheckName(kExprI32AtomicLoad8U, "i32.atomic.load8_u");
  CheckName(kExprI32AtomicLoad16U, "i32.atomic.load16_u");
  CheckName(kExprI64AtomicLoad8U, "i64.atomic.load8_u");
  CheckName(kExprI64AtomicLoad16U, "i64.atomic.load16_u");
  CheckName(kExprI64AtomicLoad32U, "i64.atomic.load32_u");
  CheckName(kExprI32AtomicStore, "i32.atomic.store");
  CheckName(kExprI64AtomicStore, "i64.atomic.store");
  CheckName(kExprI32AtomicStore8U, "i32.atomic.store8");
  CheckName(kExprI32AtomicStore16U, "i32.atomic.store16");
  CheckName(kExprI64AtomicStore8U, "i64.atomic.store8");
  CheckName(kExprI64AtomicStore16U, "i64.atomic.store16");
  CheckName(kExprI64AtomicStore32U, "i64.atomic.store32");
  CheckName(kExprI32AtomicAdd, "i32.atomic.rmw.add");
  CheckName(kExprI64AtomicAdd, "i64.atomic.rmw.add");
  CheckName(kExprI32AtomicAdd8U, "i32.atomic.rmw8.add_u");
  CheckName(kExprI32AtomicAdd16U, "i32.atomic.rmw16.add_u");
  CheckName(kExprI64AtomicAdd8U, "i64.atomic.rmw8.add_u");
  CheckName(kExprI64AtomicAdd16U, "i64.atomic.rmw16.add_u");
  CheckName(kExprI64AtomicAdd32U, "i64.atomic.rmw32.add_u");
  CheckName(kExprI32AtomicSub, "i32.atomic.rmw.sub");
  CheckName(kExprI64AtomicSub, "i64.atomic.rmw.sub");
  CheckName(kExprI32AtomicSub8U, "i32.atomic.rmw8.sub_u");
  CheckName(kExprI32AtomicSub16U, "i32.atomic.rmw16.sub_u");
  CheckName(kExprI64AtomicSub8U, "i64.atomic.rmw8.sub_u");
  CheckName(kExprI64AtomicSub16U, "i64.atomic.rmw16.sub_u");
  CheckName(kExprI64AtomicSub32U, "i64.atomic.rmw32.sub_u");
  CheckName(kExprI32AtomicAnd, "i32.atomic.rmw.and");
  CheckName(kExprI64AtomicAnd, "i64.atomic.rmw.and");
  CheckName(kExprI32AtomicAnd8U, "i32.atomic.rmw8.and_u");
  CheckName(kExprI32AtomicAnd16U, "i32.atomic.rmw16.and_u");
  CheckName(kExprI64AtomicAnd8U, "i64.atomic.rmw8.and_u");
  CheckName(kExprI64AtomicAnd16U, "i64.atomic.rmw16.and_u");
  CheckName(kExprI64AtomicAnd32U, "i64.atomic.rmw32.and_u");
  CheckName(kExprI32AtomicOr, "i32.atomic.rmw.or");
  CheckName(kExprI64AtomicOr, "i64.atomic.rmw.or");
  CheckName(kExprI32AtomicOr8U, "i32.atomic.rmw8.or_u");
  CheckName(kExprI32AtomicOr16U, "i32.atomic.rmw16.or_u");
  CheckName(kExprI64AtomicOr8U, "i64.atomic.rmw8.or_u");
  CheckName(kExprI64AtomicOr16U, "i64.atomic.rmw16.or_u");
  CheckName(kExprI64AtomicOr32U, "i64.atomic.rmw32.or_u");
  CheckName(kExprI32AtomicXor, "i32.atomic.rmw.xor");
  CheckName(kExprI64AtomicXor, "i64.atomic.rmw.xor");
  CheckName(kExprI32AtomicXor8U, "i32.atomic.rmw8.xor_u");
  CheckName(kExprI32AtomicXor16U, "i32.atomic.rmw16.xor_u");
  CheckName(kExprI64AtomicXor8U, "i64.atomic.rmw8.xor_u");
  CheckName(kExprI64AtomicXor16U, "i64.atomic.rmw16.xor_u");
  CheckName(kExprI64AtomicXor32U, "i64.atomic.rmw32.xor_u");
  CheckName(kExprI32AtomicExchange, "i32.atomic.rmw.xchg");
  CheckName(kExprI64AtomicExchange, "i64.atomic.rmw.xchg");
  CheckName(kExprI32AtomicExchange8U, "i32.atomic.rmw8.xchg_u");
  CheckName(kExprI32AtomicExchange16U, "i32.atomic.rmw16.xchg_u");
  CheckName(kExprI64AtomicExchange8U, "i64.atomic.rmw8.xchg_u");
  CheckName(kExprI64AtomicExchange16U, "i64.atomic.rmw16.xchg_u");
  CheckName(kExprI64AtomicExchange32U, "i64.atomic.rmw32.xchg_u");
  CheckName(kExprI32AtomicCompareExchange, "i32.atomic.rmw.cmpxchg");
  CheckName(kExprI64AtomicCompareExchange, "i64.atomic.rmw.cmpxchg");
  CheckName(kExprI32AtomicCompareExchange8U, "i32.atomic.rmw8.cmpxchg_u");
  CheckName(kExprI32AtomicCompareExchange16U, "i32.atomic.rmw16.cmpxchg_u");
  CheckName(kExprI64AtomicCompareExchange8U, "i64.atomic.rmw8.cmpxchg_u");
  CheckName(kExprI64AtomicCompareExchange16U, "i64.atomic.rmw16.cmpxchg_u");
  CheckName(kExprI64AtomicCompareExchange32U, "i64.atomic.rmw32.cmpxchg_u");
  // https://github.com/WebAssembly/threads/blob/main/proposals/threads/Overview.md#fence-operator
  CheckName(kExprAtomicFence, "atomic.fence");
}

}  // namespace wasm
}  // namespace internal
}  // namespace v8
