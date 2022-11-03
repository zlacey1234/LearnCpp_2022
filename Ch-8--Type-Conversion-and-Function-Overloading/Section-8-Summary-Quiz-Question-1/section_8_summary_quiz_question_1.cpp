

int main() {
    // 1a. 
    int a{ 5 };
    
    // No conversion needed

    // ------------------------------------------------------------------------------------------ //

    // 1b. 
    int b{ 'a' };
    
    // Numeric promotion (char) to (int)

    // ------------------------------------------------------------------------------------------ //

    // 1c. 
    //int c{ 5.4 };
    
    // Won't compile due to narrowing conversion (double) to (int)
    
    // ------------------------------------------------------------------------------------------ //
    
    // 1d. 
    int d{ true };
    
    // Numeric promotion (bool) to (int)
    
    // ------------------------------------------------------------------------------------------ //
    
    // 1e.
    int e{ static_cast<int>(5.4) };
    
    // Numeric conversion (double) to (int) via explicit type cast
    
    // ------------------------------------------------------------------------------------------ //
    
    // 1f. 
    double f{ 5.0f };
    
    // Numeric promotion (float) to (double)
    
    // ------------------------------------------------------------------------------------------ //
    
    // 1g.
    double g{ 5 };
    
    // Numeric conversion (int) to (double)
    
    // ------------------------------------------------------------------------------------------ //
    
    // 1h.
    long h{ 5 };
    
    // Numeric conversion (int) to (long)
    
    // ------------------------------------------------------------------------------------------ //
    
    // 1i.
    //float i{ f };
    
    // Won't compile due to narrowing conversion (double) to (float)
    
    // ------------------------------------------------------------------------------------------ //
    
    // 1j.
    float j{ 5.0 };
    
    // Numeric conversion (double) to (float). 
    // This is allowed since 5.0 is constexpr and fits the range of the float. 
    

    return 0;
}