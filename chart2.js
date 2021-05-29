var data = [["单手下压", 100], ["其他动作", 100], ["双手捂耳朵", 100], ["举手", 90], ["向左平移", 100], ["双手压缩", 94.7], ["手指点击", 92.3], ["向右平移", 100], ["双手旋转", 92.8], ["单手抓取", 92.5], ["竖大拇指", 100], ["双手上抬", 100]];

var dateList = data.map(function (item)
{
    return item[0];
});
var valueList = data.map(function (item)
{
    return item[1];
});

option = {

    // Make gradient line here
    visualMap: [{
        show: false,
        type: 'continuous',
        seriesIndex: 0,
        min: 0,
        max: 400
    }],


    title: [{
        left: 'center',
        text: 'Gradient along the y axis'
    }],
    tooltip: {
        trigger: 'axis'
    },
    xAxis: [{
        data: dateList,
        name: "手势",
        nameLocation: 'end',
        axisLabel:
        {
            interval: 0,
            formatter: function (value)
            {
                var str = value.split("");
                return str.join("\n");
            }

        }
    }],
    yAxis: [{
    }],
    grid: [{
        bottom: '60%'
    }],
    series: [{
        type: 'line',
        showSymbol: false,
        data: valueList
    }]
};
