NumberUtils= {}
NumberUtils.clamp = function (min, max, value)
    if value < min then
        return min
    elseif value > max then
        return max
    else
        return value
    end
end