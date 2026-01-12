function character = adsbCharSet(index)
    %
    % Returns the ADS-B character from the given index.
    %

    charSet = [ ...
        "?", "A", "B", "C", "D", "E", "F", "G", "H", "I", ...       % 10
        "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", ...       % 20
        "T", "U", "V", "W", "X", "Y", "Z", "?", "?", "?", ...       % 30
        "?", "?", " ", "?", "?", "?", "?", "?", "?", "?", ...       % 40
        "?", "?", "?", "?", "?", "?", "?", "?", "0", "1", ...       % 50
        "2", "3", "4", "5", "6", "7", "8", "9", "_", "?", ...       % 60
        "?", "?", "?", "?"];                                        % 64

    if index > 64
        character = 0;
    else
        character = charSet(index);
    end

end
