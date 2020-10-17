#!/bin/sh -e

cd src/models

mkdir -p generated

atdgen -t -o ./generated/Protocol_v1 Protocol_v1.atd
atdgen -bs -o ./generated/Protocol_v1 Protocol_v1.atd
