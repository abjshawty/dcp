package main

type ExprNode struct {
	val         string
	left, right *ExprNode
}

func evalExpr(root *ExprNode) float64 {
	if root.left == nil && root.right == nil {
		v := 0.0
		for _, c := range root.val {
			v = v*10 + float64(c-'0')
		}
		return v
	}
	l := evalExpr(root.left)
	r := evalExpr(root.right)
	switch root.val {
	case "+":
		return l + r
	case "-":
		return l - r
	case "*":
		return l * r
	default:
		return l / r
	}
}

func problem50() {
	println("Problem 50:")
	root := &ExprNode{val: "*",
		left:  &ExprNode{val: "+", left: &ExprNode{val: "3"}, right: &ExprNode{val: "2"}},
		right: &ExprNode{val: "+", left: &ExprNode{val: "4"}, right: &ExprNode{val: "5"}},
	}
	if evalExpr(root) != 45 {
		panic("assertion failed")
	}
	println("All Tests Passed")
}
