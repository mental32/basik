#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <error.h>
#include <argp.h>

// #include "core/basik.h"


/* Program documentation. */
static char argp_program_doc[] = "TODO";

/* The options we understand. */
static struct argp_option options[] = {
    {"version", 'v', 0, 0, "Version." },
    { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
    char *source;
};

/* Parse a single option. */
static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
    switch (key) {
        case 'v':
            exit(0);

        case ARGP_KEY_NO_ARGS:
            argp_usage(state);

        default:
            return ARGP_ERR_UNKNOWN;
    }
}

/* argp parser. */
static struct argp argp = { options, parse_opt, args_doc, argp_program_doc };


int main(int argc, char **argv)
{
    argp_parse(&argp, argc, argv, 0, 0, 0);

    // State *machine = State_New();

    // if SOURCE_FILE
    // {
    //     Basik_Parse(sources, machine);

    //     return basik_exec(machine);
    // }
}
