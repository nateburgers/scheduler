#!/usr/bin/env node
// schedule.js                                                 -*-JavaScript-*-

/**
 * @class ArgumentUtil
 */
class ArgumentUtil {
    // CLASS METHODS
    static default(argument, defaultValue) {
        if (null === argument || undefined === argument) {
            return defaultValue;                                      // RETURN
        }

        return argument;
    }
}

/**
 * @class IntVectorRef
 */
class IntVectorRef {
    // CREATORS
    /**
     * @constructor
     *
     * @param {Int32Array} int32Array
     * @param {Integer}    [beginIdx = 0]
     * @param {Integer}    [endIdx   = int32Array.length]
     * @param {Integer}    [stride   = 1]
     */
    constructor(int32Array,
                beginIdx = 0,
                endIdx   = int32Array.length,
                stride   = 1) {
        this.d_int32Array = int32Array;
        this.d_beginIdx   = beginIdx;
        this.d_endIdx     = endIdx;
        this.d_stride     = stride;
    }

    // ACCESSORS
    /**
     * @method element
     *
     * @param {Integer} index
     *
     * @return {Integer}
     */
    element(index) {
        return this.d_int32Array[this.d_beginIndex + stride * index];
    }

    // MANIPULATORS
    /**
     * @method setElement
     *
     * @param {Integer} index
     * @param {Integer} value
     */
    setElement(index, value) {
        this.d_int32Array[this.d_beginIndex + stride * index] = value;
    }
}

/**
 * @class IntVector
 */
class IntVector {
    // CREATORS
    /**
     * @constructor
     *
     * @param {...Integer} [elements = []]
     */
    constructor(...elements) {
        this.d_int32Array = Int32Array.from(elements);
    }

    // PROPERTIES
    get length() {
        return this.d_int32Array.length;
    }

    // ACCESSORS
    element(index) {
        return this.d_int32Array[index];
    }

    // MANIPULATORS
    /**
     * @method ref
     *
     * @return {IntVectorRef}
     */
    ref() {
        return new IntVectorRef(this.d_int32Array);
    }

    setElement(index, int32) {
        this.d_int32Array[index] = int32;
    }

    // ITERATORS
    [Symbol.iterator]() {
        return this.d_int32Array[Symbol.iterator]();
    }
}

/**
 * @class IntVectorUtil
 */
class IntVectorUtil {
}

/**
 * @class IntMatrix
 */
class IntMatrix {
}

/**
 * @class IntMathUtil
 */
class IntMathUtil {
    // CLASS METHODS
    static leastCommonFactor(a, b) {
        if (0 === b) {
            return a;
        }

        return IntMathUtil.leastCommonFactor(b, a % b);
    }
}
