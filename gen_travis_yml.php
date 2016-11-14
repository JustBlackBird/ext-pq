#!/usr/bin/env php
# autogenerated file; do not edit
language: c

addons:
 postgresql: 9.4
 apt:
  packages:
   - php5-cli
   - php-pear

env:
 global:
  - PQ_DSN="postgres://postgres@localhost/test"
 matrix:
<?php

$gen = include "./travis/pecl/gen-matrix.php";
$env = $gen([
	"PHP" => ["7.0", "7.1", "master"],
	"enable_debug",
	"enable_maintainer_zts",
	"enable_json",
]);
foreach ($env as $e) {
	printf("  - %s\n", $e);
}

?>

before_script:
 - make -f travis/pecl/Makefile php
 - make -f travis/pecl/Makefile pecl PECL=raphf:raphf:2.0.0
 - make -f travis/pecl/Makefile ext PECL=pq
 - psql -U postgres -c "CREATE DATABASE test"

script:
 - make -f travis/pecl/Makefile test

sudo: false
