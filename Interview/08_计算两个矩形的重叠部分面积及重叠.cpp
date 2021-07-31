/*
 * @Author: Henry
 * @Date: 2021-07-31 20:22:25
 * @LastEditTime: 2021-07-31 20:33:26
 * @Description: 
 */

/**
 * @description: 
 * 计算两个矩形框的重叠面积及比率
 * 参数：x、y为矩阵左下角坐标值，h、w为矩形的高和宽
 */
float overlapRate(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2)
{
    int endx = max(x1 + w1, x2 + w2);
    int startx = min(x1, x2);
    int width = w1 + w2 - (endx - startx);  // 重叠部分宽
    int endy = max(y1 + h1, y2 + h2);
    int starty = min(y1, y2);
    int height = h1 + h2 - (endy - starty);  // 重叠部分高
    // 判断重叠部分是否存在
    if (width > 0 && height > 0) {
        int area = width * height;  // 重叠部分面积
        int area1 = w1 * h1;
        int area2 = w2 * h2;
        float ratio = (float)area / (area1 + area2 - area);
        return ratio;
    } else {
        // 不重叠：算出来的width或height小于等于0
        return 0.0;
    }
}

