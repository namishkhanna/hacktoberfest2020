function hasComplexRoot(a, b, c) {
    // we know sqrt(b^2 - 4ac) < 0 would result in complex number
    return (Math.pow(b, 2) - 4*a*c) < 0
}

module.exports = function (a, b, c) {
    if (hasComplexRoot(a, b, c)) console.warn("Evaluating a quadratic formula with complex roots")
    return [(Math.pow(b, 2) + Math.sqrt(Math.pow(b, 2) - 4*a*c)/(2*a)), (Math.pow(b, 2) - Math.sqrt(Math.pow(b, 2) - 4*a*c)/(2*a))] 
}