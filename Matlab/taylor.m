function taylor(x);
    gus = 0
    for i = 1:2:19
        gus = gus + ((x^i)/factorial(i) * (-1)^((i -1)/2))
    end
end


