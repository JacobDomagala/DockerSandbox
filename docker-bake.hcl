target "build" {
  target = "build"
  context = "."
  dockerfile = "ci/dockerfile"
  platforms = [
    "linux/amd64"
  ]
  ulimits = [
    "core=0"
  ]
}

target "build-all" {
  name = "build-${replace(item.image, ".", "-")}"
  inherits = ["build"]
  tags = ["jdomagala:project-${item.image}"]
  output = [
    {
      type = "local"
      dest = "docker-output/${item.image}"
    }
  ]
  args = {
    BASE_IMAGE = "${item.image}"
  }

  matrix = {
    item = [
      {
        image = "22.04"
      },
      {
        image = "24.04"
      }
    ]
  }
}