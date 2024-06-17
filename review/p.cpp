bool juegoTerminado = false;
    while (!juegoTerminado) {
        int x, y;

        // Turno del jugador 1
        std::cout << jugador1.getNombre() << ", ingresa las coordenadas para atacar (x y): ";
        std::cin >> x >> y;
        std::cout << jugador1.getNombre() << " ataca (" << x << ", " << y << "): "
                  << (jugador2.getTablero().atacar(x, y) ? "Golpe!" : "Fallo!") << std::endl;
        std::cout << "Tablero " << jugador2.getNombre() << " después del ataque:" << std::endl;
        jugador2.getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador2 están hundidos
        if (jugador2.todosBarcosHundidos()) {
            std::cout << jugador1.getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }

        // Turno del jugador 2
        std::cout << jugador2.getNombre() << ", ingresa las coordenadas para atacar (x y): ";
        std::cin >> x >> y;
        std::cout << jugador2.getNombre() << " ataca (" << x << ", " << y << "): "
                  << (jugador1.getTablero().atacar(x, y) ? "Golpe!" : "Fallo!") << std::endl;
        std::cout << "Tablero " << jugador1.getNombre() << " después del ataque:" << std::endl;
        jugador1.getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador1 están hundidos
        if (jugador1.todosBarcosHundidos()) {
            std::cout << jugador2.getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }
    }


        while (!juegoTerminado) {
        int x, y;
        bool ataqueValido;

        // Turno del jugador 1
        do {
            std::cout << jugador1.getNombre() << ", ingresa las coordenadas para atacar (x y): ";
            std::cin >> x >> y;
            ataqueValido = jugador2.getTablero().atacar(x, y);
            if (!ataqueValido) {
                std::cout << "Ataque no válido. Intenta de nuevo." << std::endl;
            }
        } while (!ataqueValido);

        if (jugador2.getTablero().atacar(x, y)) {
            std::cout << "¡Tocado!" << std::endl;
        } else {
            std::cout << "Agua..." << std::endl;
        }

        std::cout << "Tablero " << jugador2.getNombre() << " después del ataque:" << std::endl;
        jugador2.getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador 2 están hundidos
        if (jugador2.todosBarcosHundidos()) {
            std::cout << jugador1.getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }

        // Turno del jugador 2
        do {
            std::cout << jugador2.getNombre() << ", ingresa las coordenadas para atacar (x y): ";
            std::cin >> x >> y;
            ataqueValido = jugador1.getTablero().atacar(x, y);
            if (!ataqueValido) {
                std::cout << "Ataque no válido. Intenta de nuevo." << std::endl;
            }
        } while (!ataqueValido);

        if (jugador1.getTablero().atacar(x, y)) {
            std::cout << "¡Tocado!" << std::endl;
        } else {
            std::cout << "Agua..." << std::endl;
        }

        std::cout << "Tablero " << jugador1.getNombre() << " después del ataque:" << std::endl;
        jugador1.getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador 1 están hundidos
        if (jugador1.todosBarcosHundidos()) {
            std::cout << jugador2.getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }
    }