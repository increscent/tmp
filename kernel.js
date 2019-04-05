var mean = (xs) => Math.round(xs.reduce((acc, x) => acc + x, 0) / xs.length);
var median = (xs) => {
    var copy = xs.slice();
    copy.sort((a, b) => a - b);
    return copy[Math.floor(copy.length / 2)];
};
var mask = (m) => {
    return (xs) => {
        var total = 0;
        for (var i = 0; i < xs.length; i++)
        {
            total += xs[i] * m[i];
        }
        return total;
    };
};
var sobel_x = (xs) => mask([-1, 0, 1, -2, 0, 2, -1, 0, 1])(xs) / 8;
var sobel_y = (xs) => mask([-1, -2, -1, 0, 0, 0, 1, 2, 1])(xs) / 8;
var gradient = (xs) => Math.sqrt(Math.pow(sobel_x(xs), 2) + Math.pow(sobel_y(xs), 2));

function kernel_that(img, func) {
    var new_img = img.map(xs => xs.slice());

    for (var i = 0; i < img.length; i++) {
        for (var j = 0; j < img[i].length; j++) {
            var connected = [
                get_point(img, i-1, j-1),
                get_point(img, i-1, j),
                get_point(img, i-1, j+1),
                get_point(img, i, j-1),
                get_point(img, i, j),
                get_point(img, i, j+1),
                get_point(img, i+1, j-1),
                get_point(img, i+1, j),
                get_point(img, i+1, j+1),
            ];

            new_img[i][j] = func(connected);
        }
    }

    return new_img;
}

function get_point(img, row, col) {
    if (row < 0 || row >= img.length)
        return 0;

    if (col < 0 || col >= img[row].length)
        return 0;

    return img[row][col];
}

var img = [
    [10, 11, 9, 25, 22],
    [8, 10, 9, 26, 28],
    [9, 99, 9, 24, 25],
    [11, 11, 12, 23, 22],
    [10, 11, 9, 22, 25],
];

var img2 = [
    [0, 0, 0, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 1, 2, 1, 0],
    [0, 0, 3, 0, 0],
    [0, 0, 0, 0, 0],
];

var img3 = [
    [10, 11, 9, 25, 22],
    [8, 10, 9, 26, 28],
    [9, 8, 9, 24, 25],
    [11, 11, 12, 23, 22],
    [10, 11, 9, 22, 25],
];

var m = [1, 2, 1, 2, 4, 2, 1, 2, 1];

var m1 = [0, -1, 0, -1, 5, -1, 0, -1, 0];

console.log(kernel_that(img3, mask(m1)));
