/**
 * @param {number[][]} rectangles
 * @return {boolean}
 */
function insert_interval(tree, interval) {
    var [low, high] = interval;
    if (low == high)
        return;
    
    if (tree.interval == null) {
        tree.interval = interval;
        return;
    }
    
    var [t_low, t_high] = tree.interval;
    
    if (high == t_low) {
        tree.interval[0] = low;
        t_low = low;
    } else if (high < t_low) {
        if (tree.left == null) {
            tree.left = {
                interval,
                left: null,
                right: null,
            };
        } else {
            insert_interval(tree.left, interval);
        }
    } else if (low == t_high) {
        tree.interval[1] = high;
        t_high = high;
    } else if (low > t_high) {
        if (tree.right == null) {
            tree.right = {
                interval,
                left: null,
                right: null,
            };
        } else {
            insert_interval(tree.right, interval);
        }
    } else {
        throw 'overlap';
    }
    
    if (tree.left) {
        if (tree.left.interval[1] == t_low) {
            // assume tree.left.right is null
            tree.interval[0] = tree.left.interval[0];
            t_low = tree.left.interval[0];
            tree.left = tree.left.left;
        } else if (tree.left.interval[1] > t_low) {
            throw 'overlap';
        }
    }
    if (tree.right) {
        if (tree.right.interval[0] == t_high) {
            // assume tree.right.left is null
            tree.interval[1] = tree.right.interval[1];
            t_high = tree.right.interval[1]
            tree.right = tree.right.right;
        } else if (tree.right.interval[0] < t_high) {
            throw 'overlap';
        }
    }
}

function trees_are_equal(tree1, tree2) {
    if (tree1 == tree2)
        return true;
    
    if (tree1 == null || tree2 == null)
        return false;
    
    var [low1, high1] = tree1.interval;
    var [low2, high2] = tree2.interval;
    
    if (low1 != low2 || high1 != high2)
        return false;
    
    return trees_are_equal(tree1.left, tree2.left) && trees_are_equal(tree1.right, tree2.right);
}

var isRectangleCover = function(rectangles) {
    // try sorting rectangles by x_min
    var [x_min, y_min, x_max, y_max] = rectangles[0];
    
    for (var i = 0; i < rectangles.length; i++) {
        var [x1, y1, x2, y2] = rectangles[i];
        if (x1 < x_min) x_min = x1;
        if (y1 < y_min) y_min = y1;
        if (x2 > x_max) x_max = x2;
        if (y2 > y_max) y_max = y2;
    }
    
    var sorted_x_positions = [];
    var x_positions = {};
    
    var insert_x_position = (x_value, interval) => {
        if (x_positions[x_value]) {
            insert_interval(x_positions[x_value], interval);
        } else {
            x_positions[x_value] = {
                interval,
                left: null,
                right: null,
            };
            
            if (!sorted_x_positions.length 
                || x_value > sorted_x_positions[sorted_x_positions.length - 1]) {
                sorted_x_positions.push(x_value);
            } else {
                for (var i = 0; i < sorted_x_positions.length; i++) {
                    if (x_value < sorted_x_positions[i]) {
                        sorted_x_positions.splice(i, 0, x_value);
                        break;
                    }
                }
            }
        }
    };
    
    insert_x_position(x_min, [y_min, y_max]);
    
    var rectangles_used = 0;
    
    while (sorted_x_positions.length) {
        try {
            var x = sorted_x_positions.shift();
            
            if (x == x_max) {
                if (!(x_positions[x].interval[0] == y_min && x_positions[x].interval[1] == y_max)) {
                    console.log('hi');
                    return false;
                }
                break;
            }
            
            var tree = {
                interval: null,
                left: null,
                right: null,
            };
            
            for (var i = 0; i < rectangles.length; i++) {
                if (rectangles[i][0] == x) {
                    var interval = [rectangles[i][1],rectangles[i][3]];
                    insert_interval(tree, interval.slice());
                    insert_x_position(rectangles[i][2], interval.slice());
                    rectangles_used++;
                }
            }
            
            if (!trees_are_equal(tree, x_positions[x])) {
                console.log(JSON.stringify(tree));
                console.log(JSON.stringify(x_positions[x]));
                return false;
            }
        } catch (e) {
            console.log(e);
            return false;
        }
    }
    
    return (rectangles_used === rectangles.length);
};

var rects = require('./rects.js');

console.log(isRectangleCover(rects));
